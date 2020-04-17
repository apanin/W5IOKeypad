// This #include statement was automatically added by the Particle IDE.
#include <math.h>
#define M_PI acos(-1.0)

#include "W5IOKeypad.h"

#define GND A0
#define IO1 A1
#define IO2 A2
#define IO3 A3
#define IO4 A4
#define IO5 A5

W5IOKeypad Keypad( GND, IO1, IO2, IO3, IO4, IO5 );

// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_SSD1306.h>
#include "Adafruit_GFX.h"

//  //Use I2C with no reset pin
#define OLED_RESET -1
Adafruit_SSD1306 oled(OLED_RESET);

// interval at which screen refreshes/keypad input is taken
int gameRate = 50;
int width = 128;
int height = 50;

// snake game elements
int length = 1;
// int x,y = 0;
int bodyX [20];
int bodyY [20];
double direction = 0;
//placement of the dot
int dotx, doty = 10;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  bodyX[0] = 10;
  bodyY[0] = 10;
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  oled.display(); // show splashscreen
  pinMode(D7, OUTPUT);
  dotx = (int)(random(width));
  doty = (int)(random(height));
  delay(gameRate);
  oled.clearDisplay();
}

void loop() {
    oled.clearDisplay();
    displayElements();
    oled.drawPixel(10, 10, WHITE);
    moveSnake();
    delay(gameRate);
    digitalWrite(D7, LOW);
}

void displayElements(){
//draw board
oled.setCursor(0,0);
oled.drawRect(0,0, width, height, WHITE);
// draw food
 oled.drawPixel(dotx, doty, WHITE);
// draw snake 
 for (int i = 0; i < length; i++){
 oled.drawPixel(bodyX[i], bodyY[i], WHITE);
 }
 
 //draw score
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(width - 20,height + 5);
  oled.println(length - 1);
 //display elements
 oled.display();
}

void touch(){
    if (bodyX[0] == dotx && bodyY[0] == doty){
        dotx = (int)(random(width-2)) + 2;
        doty = (int)(random(height - 2)) + 2;
        //add body member to the snake
        length++;
    }
}

void moveSnake(){
    switch(Keypad.ReadButtons()){
        case 11: direction = M_PI;
        break;
        case 12: direction = M_PI * 3 / 2;
        digitalWrite(D7, HIGH);
        break;
        case 14: direction = M_PI / 2;
        digitalWrite(D7, HIGH);
        break;
        case 15: direction = 0;
        digitalWrite(D7, HIGH);
        break;
        default:
        break;
    }
    
    //update the position of the rest of the body
    for (int i = length; i > 0; i--){
        bodyX[i] = bodyX[i - 1];
        bodyY[i] = bodyY[i - 1];
    }
    //update the position of the head
    bodyX [0] = (bodyX[0] + (int)cos(direction)) % width;
    bodyY[0] = (bodyY[0] + (int)sin(direction)) % height;
    
    //borders
    if (bodyX[0] < 0) bodyX[0] = width-2;
    if (bodyX[0]> (width - 2)) bodyX[0] = 2;
    if (bodyY[0] < 0) bodyY[0] = height - 2;
    if (bodyY[0] > (height -2)) bodyY[0] =  2;
    //check if the player has touched something
    touch();
}

