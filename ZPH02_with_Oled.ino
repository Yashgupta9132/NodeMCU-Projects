#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define RXD2 16
#define TXD2 17

byte buffer[9];
int idx = 0;

// AQI calculation
int getAQI(float pm) {
  if (pm <= 12) return map(pm, 0, 12, 0, 50);
  else if (pm <= 35.4) return map(pm, 12, 35, 51, 100);
  else if (pm <= 55.4) return map(pm, 35, 55, 101, 150);
  else if (pm <= 150.4) return map(pm, 55, 150, 151, 200);
  else return 300; // simplified
}

String getLevel(int aqi) {
  if (aqi <= 50) return "Good";
  else if (aqi <= 100) return "Moderate";
  else if (aqi <= 150) return "Unhealthy";
  else return "Danger";
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  Serial.println("System Ready");
}

void loop() {
  while (Serial2.available()) {
    byte b = Serial2.read();

    if (idx == 0 && b != 0xFF) return;

    buffer[idx++] = b;

    if (idx == 9) {
      idx = 0;

      int pm25 = buffer[4];
      int aqi = getAQI(pm25);
      String level = getLevel(aqi);

      // Serial debug
      Serial.print("PM2.5: ");
      Serial.print(pm25);
      Serial.print("  AQI: ");
      Serial.println(aqi);

      // OLED display
      display.clearDisplay();

      display.setTextSize(2);
      display.setCursor(0, 0);
      display.print("PM:");
      display.print(pm25);

      display.setTextSize(2);
      display.setCursor(0, 25);
      display.print("AQI:");
      display.print(aqi);

      display.setTextSize(1);
      display.setCursor(0, 50);
      display.print(level);

      display.display();
    }
  }
}
