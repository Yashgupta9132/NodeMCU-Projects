//KY-008 laser module

const int LASER_PIN = 13;   // GPIO connected to 13 pin

void setup() {
  pinMode(LASER_PIN, OUTPUT);
  digitalWrite(LASER_PIN, LOW);  // laser off at start
}

void loop() {
  // blink laser
  digitalWrite(LASER_PIN, HIGH); // laser ON
  delay(1000);

  digitalWrite(LASER_PIN, LOW);  // laser OFF
  delay(1000);
}
