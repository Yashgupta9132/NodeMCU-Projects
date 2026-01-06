// 3-pin LDR Module (VCC, GND, DO only)

const int LDR_DO_PIN = 4;   // Digital output from LDR module
const int LED_PIN    = 2;   // Onboard LED (optional)

void setup() {
  Serial.begin(115200);
  pinMode(LDR_DO_PIN, INPUT);   // Read the digital signal
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int state = digitalRead(LDR_DO_PIN);  // 0 or 1
  
  // Most LM393 modules output LOW in light, HIGH in dark
  // Test and swap HIGH/LOW if needed
  if (state == HIGH) {
    digitalWrite(LED_PIN, HIGH);     // Turn on LED when dark
    Serial.println("DARK");
  } else {
    digitalWrite(LED_PIN, LOW);      // Turn off LED when bright
    Serial.println("BRIGHT");
  }

  delay(200);
}
