#define PIR_PIN 14
#define LED_BUILTIN 2   // onboard LED pin (usually 2 on ESP32)

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("PIR Motion Sensor Test (Built-in LED)");
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    Serial.println(" Motion Detected!");
    digitalWrite(LED_BUILTIN, HIGH);   // LED ON
  } else {
    Serial.println("No Motion");
    digitalWrite(LED_BUILTIN, LOW);    // LED OFF
  }

  delay(500); // check every half second
}
