#include "W5IOKeypad.h"

//plugged keypad to A0, A1, A2, A3, A4, A5 respectively
#define GND A0
#define IO1 A1
#define IO2 A2
#define IO3 A3
#define IO4 A4
#define IO5 A5

W5IOKeypad Keypad( GND, IO1, IO2, IO3, IO4, IO5 );

void setup() {
  Serial.begin(9600);
  while(!Serial);
  //make d7 led light when key is pressed
  pinMode(D7, OUTPUT);
}

void loop() {
    Keypad.ReadButtons();
    Keypad.printKey();
    delay(500);
}