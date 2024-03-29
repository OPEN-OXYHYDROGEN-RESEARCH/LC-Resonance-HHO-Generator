/*
  LCDKeypad.cpp
*/

// include this library's header files
#include <Arduino.h>
#include "LCDKeypad\LCDKeypad.h"

LCDKeypad::LCDKeypad() : LiquidCrystal(8, 9, 4, 5, 6, 7)
{
}

LCDKeypad::LCDKeypad(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : LiquidCrystal(rs, enable, d4, d5, d6, d7)
{
}

int LCDKeypad::button()
{
  static int NUM_KEYS = 5;
  static int adc_key_val[5] = {
      30, 150, 360, 535, 760};
  int k, input;
  input = analogRead(0);
  for (k = 0; k < NUM_KEYS; k++)
  {
    if (input < adc_key_val[k])
    {
      return k;
    }
  }
  if (k >= NUM_KEYS)
    k = -1; // No valid key pressed
  return k;
}