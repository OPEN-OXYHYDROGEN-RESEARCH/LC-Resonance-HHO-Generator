/*
  LCDKeypad.h
*/

// Ensures this library definition is only included once
#ifndef LCDKeypad_h
#define LCDKeypad_h

// include other dependencies header files
#include <LiquidCrystal.h>

// library interface description
#define KEYPAD_NONE -1
#define KEYPAD_RIGHT 0
#define KEYPAD_UP 1
#define KEYPAD_DOWN 2
#define KEYPAD_LEFT 3
#define KEYPAD_SELECT 4

class LCDKeypad: public LiquidCrystal
{
  public:
    LCDKeypad();
    LCDKeypad(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
         int button();
};


#endif

