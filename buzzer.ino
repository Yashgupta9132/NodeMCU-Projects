// 2 Pin Active buzzer has 2 pin + and - 
// +ve will be given the signal 
// -ve is the ground 

#define BUZZER_PIN 23

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {  // 3 short beeps
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
  delay(1000);  // pause, then repeat
}




