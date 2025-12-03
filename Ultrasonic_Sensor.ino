// This is the code for HC-SR04
// here the vcc will be given 5v 
// gnd is ground 
// trig is using gpio5
// echo is using gpio18 after voltage is stepped down to 3.3v 

#define TRIG_PIN 5    // GPIO5 
#define ECHO_PIN 18   // GPIO18

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
  delay(100);
  Serial.println("HC-SR04 debug start (powered at 3.3V).");
  Serial.println("Make sure sensor VCC=3.3V, GND common, TRIG=GPIO5, ECHO=GPIO18");
}

void loop() {
  unsigned long beforeHigh, afterHigh;
  long duration;
  float distanceCm;

  // Read echo pin idle state
  int idle = digitalRead(ECHO_PIN);

  // Trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Immediately sample echo pin a few times to observe any change
  beforeHigh = micros();
  // Wait up to 35 ms for HIGH, measuring with pulseIn (timeout 35ms)
  duration = pulseIn(ECHO_PIN, HIGH, 35000);
  afterHigh = micros();

  Serial.print("Idle:");
  Serial.print(idle);
  Serial.print("  pulseIn_duration(us): ");
  Serial.print(duration);
  Serial.print("  micros_elapsed: ");
  Serial.print((long)(afterHigh - beforeHigh));
  
  if (duration > 0) {
    distanceCm = (duration * 0.0343) / 2.0;
    Serial.print("  Distance: ");
    Serial.print(distanceCm, 2);
    Serial.println(" cm");
  } else {
    Serial.println("  NO ECHO");
  }

  delay(250);
}
