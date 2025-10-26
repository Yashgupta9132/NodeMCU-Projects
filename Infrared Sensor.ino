#define IR_PIN 15
#define LED_BUILTIN 2   // onboard LED

void setup() {
  pinMode(IR_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("IR Sensor Test (Built-in LED)");
}

void loop() {
  int obstacle = digitalRead(IR_PIN);

  if (obstacle == LOW) {  
    // Many IR modules output LOW when obstacle is detected
    Serial.println("Obstacle Detected!");
    digitalWrite(LED_BUILTIN, HIGH); // LED ON
  } else {
    Serial.println("Clear Path");
    digitalWrite(LED_BUILTIN, LOW);  // LED OFF
  }
  
  delay(500);
}
