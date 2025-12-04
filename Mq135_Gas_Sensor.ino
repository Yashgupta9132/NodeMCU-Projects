// This is a test for MQ135 sensor 

#define MQ135_AQ 34   // analog input
#define MQ135_DQ 27   // digital input

void setup() {
  Serial.begin(115200);
  pinMode(MQ135_DQ, INPUT);
  delay(1000);

  Serial.println("MQ135 Test Start");
}

void loop() {
  int analogValue = analogRead(MQ135_AQ);   // 0–4095
  int digitalValue = digitalRead(MQ135_DQ); // 0 or 1

  Serial.print("Analog AQ: ");
  Serial.print(analogValue);

  Serial.print("   |   Digital DQ: ");
  Serial.println(digitalValue);

  delay(500);
}
