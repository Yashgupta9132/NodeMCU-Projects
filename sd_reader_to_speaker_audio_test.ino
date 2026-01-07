#include <FS.h>
#include <SD.h>
#include <SPI.h>

#define SD_CS    5      // SD chip select
#define DAC_PIN  25     // DAC1 to LM386 SIG
#define SAMPLE_RATE 16000
#define SAMPLE_DELAY_US (1000000UL / SAMPLE_RATE)

File wavFile;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== ESP32 WAV from SD + Speaker ===");

  // Init SD
  SPI.begin(18, 19, 23, SD_CS);
  if (!SD.begin(SD_CS)) {
    Serial.println(" SD failed!");
    return;
  }
  Serial.println(" SD OK");

  // List files
  Serial.println("Files:");
  File root = SD.open("/");
  File file = root.openNextFile();
  while (file) {
    Serial.printf("  %s (%d bytes)\n", file.name(), file.size());
    file = root.openNextFile();
  }

  // Open WAV file
  wavFile = SD.open("/crabrave.wav");
  if (!wavFile) {
    Serial.println(" /crabrave.wav not found");
    return;
  }
  Serial.printf(" Playing %s (%d bytes)\n", wavFile.name(), wavFile.size());

  // Skip 44-byte WAV header
  wavFile.seek(44);
  Serial.println(" Playing...");
}

void loop() {
  if (wavFile.available()) {
    uint8_t sample = wavFile.read();
    dacWrite(DAC_PIN, sample);
    delayMicroseconds(SAMPLE_DELAY_US);
  } else {
    Serial.println(" Done. Restarting...");
    wavFile.close();
    delay(2000);
    ESP.restart();  // play again
  }
}
