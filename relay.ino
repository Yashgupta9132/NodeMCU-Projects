int relayPin = 15;  // IN pin on relay module

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // start OFF (most modules are active-LOW)
}

void loop() {
  // ON (click) – closes NO→COM, LED turns ON
  digitalWrite(relayPin, LOW);
  delay(3000);

  // OFF (click) – opens contact, LED turns OFF
  digitalWrite(relayPin, HIGH);
  delay(3000);
}
