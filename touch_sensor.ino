// Code for 3 pin touch sensor 

const int TOUCH_PIN = 4;     // GPIO connected to SIG
const int LED_PIN   = 2;     // On‑board LED on ESP32 boards

void setup() {
  Serial.begin(115200);
  pinMode(TOUCH_PIN, INPUT);       // read digital signal
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int touched = digitalRead(TOUCH_PIN);

  if (touched == HIGH) {
    digitalWrite(LED_PIN, HIGH);   // LED on when touched
    Serial.println("Touch detected");
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(50);  // small debounce
}
