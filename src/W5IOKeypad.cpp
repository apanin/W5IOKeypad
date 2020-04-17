#include "W5IOKeypad.h"
#include "Arduino.h"

W5IOKeypad::W5IOKeypad(int pin0, int pin1, int pin2, int pin3, int pin4, int pin5)
{
  // Assign Particle pins to 5IOKey Pins
  GND = pin0; 
  IO1 = pin1; 
  IO2 = pin2; 
  IO3 = pin3; 
  IO4 = pin4; 
  IO5 = pin5; 
  curr = 0;

  // Initialize the pushbuttons pins as input:
  pinMode(GND, OUTPUT);  digitalWrite(GND, LOW);
  pinMode(IO1, INPUT_PULLUP);
  pinMode(IO2, INPUT_PULLUP);     
  pinMode(IO3, INPUT_PULLUP);     
  pinMode(IO4, INPUT_PULLUP);     
  pinMode(IO5, INPUT_PULLUP);     
}

int W5IOKeypad::ReadButtons(){
    //reinitialize current press
    curr = 0;
    //Start with the joystick
    pinMode(GND, OUTPUT);
    pinMode(IO1, INPUT_PULLUP);
    pinMode(IO2, INPUT_PULLUP);
    pinMode(IO3, INPUT_PULLUP);
    pinMode(IO4, INPUT_PULLUP);
    pinMode(IO5, INPUT_PULLUP);
    if (digitalRead(IO1)==LOW) { curr = 11; }   
    if (digitalRead(IO2)==LOW) { curr = 12; }   
    if (digitalRead(IO3)==LOW) { curr = 13; }   
    if (digitalRead(IO4)==LOW) { curr = 14; }   
    if (digitalRead(IO5)==LOW) { curr = 15; }  

    //set pin IO1 as gnd
    pinMode(GND, INPUT_PULLUP);
    pinMode(IO1, OUTPUT);
    digitalWrite(IO1, LOW);
    pinMode(IO2, INPUT_PULLUP);
    pinMode(IO3, INPUT_PULLUP);
    pinMode(IO4, INPUT_PULLUP);
    pinMode(IO5, INPUT_PULLUP);
    if (digitalRead(IO2)==LOW) { curr = 1; }   
    if (digitalRead(IO3)==LOW) { curr = 2; }   
    if (digitalRead(IO4)==LOW) { curr = 3; }   
    if (digitalRead(IO5)==LOW) { curr = 4; }  

    //set pin IO2 as gnd
    pinMode(IO1, INPUT_PULLUP);
    pinMode(IO2, OUTPUT);
    digitalWrite(IO2, LOW);   
    if (digitalRead(IO3)==LOW) { curr = 5; }   
    if (digitalRead(IO4)==LOW) { curr = 6; }   
    if (digitalRead(IO5)==LOW) { curr = 7; }  

    //set pin IO5 as gnd
    pinMode(IO2, INPUT_PULLUP);
    pinMode(IO3, OUTPUT);
    digitalWrite(IO3, LOW);    
    if (digitalRead(IO4)==LOW) { curr = 8; }   
    if (digitalRead(IO5)==LOW) { curr = 9; }  

    //set pin IO4 as gnd
    pinMode(IO3, INPUT_PULLUP);
    pinMode(IO4, OUTPUT);
    digitalWrite(IO4, LOW);    
    if (digitalRead(IO5)==LOW) { curr = 10; } 
    //if no key was pressed curr is still at 0 
    return curr;
  }

//function that prints pressed key
  void W5IOKeypad::printKey(){
    switch (curr) {
        case 1:
        Serial.println("K1 pressed");
        break;
        case 2:
        Serial.println("K2 pressed");
        break;
        case 3:
        Serial.println("K3 pressed");
        break;
        case 4:
        Serial.println("K4 pressed");
        break;
        case 5:
        Serial.println("K5 pressed");
        break;
        case 6:
        Serial.println("K6 pressed");
        break;
        case 7:
        Serial.println("K7 pressed");
        break;
        case 8:
        Serial.println("K8 pressed");
        break;
        case 9:
        Serial.println("K9 pressed");
        break;
        case 10:
        Serial.println("K10 pressed");
        break;
        case 11:
        Serial.println("Joystick left");
        break;
        case 12:
        Serial.println("Joystick up");
        break;
        case 13:
        Serial.println("Jostick pressed");
        break;
        case 14:
        Serial.println("Joystick down");
        break;
        case 15: 
        Serial.println("Joystick right");
        break;
        default:
        Serial.println("no key pressed");
        break;
    }
  }