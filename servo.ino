// using a micro servo 
// Brown / Black → GND
// Red → VCC (use 5V, not 3.3V)
// Orange / Yellow / White → Signal (connect to a GPIO pin on ESP32, e.g. GPIO 13)

#include <ESP32Servo.h>

Servo myServo;  

int servoPin = 15;  // connect servo signal pin here

void setup() {
  myServo.attach(servoPin);  
}

void loop() {
  myServo.write(0);     // move to 0 degrees
  delay(1000);
  myServo.write(90);    // move to 90 degrees
  delay(1000);
  myServo.write(180);   // move to 180 degrees
  delay(1000);
}
