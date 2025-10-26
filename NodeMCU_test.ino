// Blinking light on mcu to test its functionality 

void setup() {
  pinMode(2, OUTPUT);  // LED on GPIO 2
}

void loop() {
  digitalWrite(2, HIGH);   // turn the LED on
  delay(1000);             // wait 1 second
  digitalWrite(2, LOW);    // turn the LED off
  delay(1000);             // wait 1 second
}
