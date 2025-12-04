// This is a test code for a 4 Digit Display
#include <TM1637.h>

#define CLK 4
#define DIO 5

TM1637 tm(CLK, DIO);

void setup() {
  tm.init();
  tm.set(0);  // brightness 0–7
}

void loop() {
  tm.display(0, 1);
  tm.display(1, 2);
  tm.display(2, 3);
  tm.display(3, 4);
  delay(10000);

  // Count
  for (int i = 0; i <= 9999; i++) {
    tm.displayNum(i);
    delay(5);
  }
}
