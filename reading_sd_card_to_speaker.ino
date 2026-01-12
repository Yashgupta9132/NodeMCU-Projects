// CS → GPIO 5
// SCK → GPIO 18
// MOSI → GPIO 23
// MISO → GPIO 19
// VCC → 5V/VIN
// GND → GND

#include <FS.h>
#include <SD.h>
#include <SPI.h>

#define SD_CS    5       // SD chip select
#define DAC_PIN  25      // DAC1 to LM386 SIG
#define SAMPLE_RATE 16000
#define SAMPLE_DELAY_US (1000000UL / SAMPLE_RATE)

File wavFile;
File musicDir;
String musicFiles[50];
int fileCount = 0;
int currentFile = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n ESP32 WAV Player - Music Folder ");

  // Init SD
  SPI.begin(18, 19, 23, SD_CS);
  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card failed!");
    while(1) delay(1000);
  }
  Serial.println(" SD Card OK");

  loadMusicFiles();
  
  if (fileCount == 0) {
    Serial.println(" No WAV files in /music/ folder!");
    while(1) delay(1000);
  }
  
  Serial.printf(" Found %d music files\n", fileCount);
  listMusicFiles();

  // Play first file
  playNextFile();
}

void loop() {
  if (wavFile && wavFile.available()) {
    uint8_t sample = wavFile.read();
    dacWrite(DAC_PIN, sample);
    delayMicroseconds(SAMPLE_DELAY_US);
  } else if (wavFile) {
    // File finished
    wavFile.close();
    Serial.printf(" Finished: %s\n", musicFiles[currentFile].c_str());
    delay(1000);
    playNextFile();
  }
}

void loadMusicFiles() {
  musicDir = SD.open("/music");
  if (!musicDir) {
    Serial.println(" /music/ folder not found!");
    return;
  }
  
  File file = musicDir.openNextFile();
  while (file && fileCount < 50) {
    String name = String(file.name());
    if (name.endsWith(".WAV") || name.endsWith(".wav")) {
      musicFiles[fileCount++] = "/music/" + name;
      Serial.printf("Found: %s (%d bytes)\n", name.c_str(), file.size());
    }
    file = musicDir.openNextFile();
  }
  musicDir.close();
}

void listMusicFiles() {
  Serial.println("\nPlaylist:");
  for (int i = 0; i < fileCount; i++) {
    Serial.printf("%d. %s\n", i+1, musicFiles[i].substring(6).c_str());
  }
  Serial.println();
}

void playNextFile() {
  if (currentFile >= fileCount) {
    currentFile = 0;  // Loop back to first
    Serial.println(" Restarting playlist...");
  }
  
  String filepath = musicFiles[currentFile];
  wavFile = SD.open(filepath);
  
  if (!wavFile) {
    Serial.printf(" Failed to open %s\n", filepath.c_str());
    currentFile++;
    playNextFile();  // Skip bad file
    return;
  }
  
  // Skip 44-byte WAV header
  if (wavFile.seek(44)) {
    Serial.printf(" Playing #%d: %s (%d bytes)\n", 
                  currentFile+1, 
                  musicFiles[currentFile].substring(6).c_str(),
                  wavFile.size());
  } else {
    Serial.println(" Failed to skip WAV header");
  }
  
  currentFile++;
}


