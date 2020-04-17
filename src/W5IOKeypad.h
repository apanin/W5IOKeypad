#ifndef W5IOKeypad_h
#define W5IOKeypad_h

class W5IOKeypad
{
  public:
    W5IOKeypad(int pin0, int pin1, int pin2, int pin3, int pin4, int pin5);
    int curr;
    int ReadButtons();
    void printKey();
  private:
    int GND, IO1, IO2, IO3, IO4, IO5; 
};

#endif