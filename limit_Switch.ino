#define SWITCH_PIN 14   // connect NO to GPIO14, C to GND

void setup() {
  Serial.begin(115200);

  pinMode(SWITCH_PIN, INPUT_PULLUP);  
  // Pull-up means:
  // HIGH = not pressed
  // LOW  = pressed
}

void loop() {
  int state = digitalRead(SWITCH_PIN);

  if (state == LOW) {
    Serial.println("Switch PRESSED");
  } else {
    Serial.println("Switch released");
  }

  delay(200);
}

