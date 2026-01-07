#include <FS.h>
#include <SD.h>
#include <SPI.h>

#define SD_CS 5

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== Create New File Test ===");

  // Initialize SD
  SPI.begin(18, 19, 23, SD_CS);  // SCK, MISO, MOSI, CS
  if (!SD.begin(SD_CS)) {
    Serial.println("SD init failed!");
    return;
  }
  Serial.println("SD OK");

  // 1. Create new file
  Serial.println("\n1. Creating newfile.txt...");
  File newFile = SD.open("/newfile.txt", FILE_WRITE);
  if (!newFile) {
    Serial.println("Create FAILED");
  } else {
    newFile.println("Hello from ESP32!");
    newFile.println("Created at: " + String(millis()));
    newFile.println("SD card write test OK");
    newFile.close();
    Serial.println("newfile.txt created & written");
  }

  // 2. Verify by reading it back
  Serial.println("\n2. Reading newfile.txt...");
  File readFile = SD.open("/newfile.txt");
  if (readFile) {
    Serial.println("Contents:");
    while (readFile.available()) {
      Serial.write(readFile.read());
    }
    readFile.close();
    Serial.println("\nRead OK");
  } else {
    Serial.println("Read FAILED");
  }

  // 3. List all files to confirm
  Serial.println("\n3. All files:");
  File root = SD.open("/");
  File file = root.openNextFile();
  while (file) {
    Serial.printf("  %s (%d bytes)\n", file.name(), file.size());
    file = root.openNextFile();
  }

  Serial.println("\nFile creation test COMPLETE!");
}

void loop() {
  // nothing
}
