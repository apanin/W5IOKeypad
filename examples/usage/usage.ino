// Example usage for W5IOKeypad library by Nina Parenteau.

#include "W5IOKeypad.h"

// Initialize objects from the lib
W5IOKeypad w5IOKeypad;

void setup() {
    // Call functions on initialized library objects that require hardware
    w5IOKeypad.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    w5IOKeypad.process();
}
