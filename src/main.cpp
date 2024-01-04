
/*
  H2OtoHHO.cpp
*/

// ensure this library header is already included
#include <Arduino.h>
#include "H2OtoHHO.h"
// #include "Localize.h"

H2OtoHHO gen;

//  AD9850 gen.dds_pulse(10, 9, 8, 7, 6); //  SW SPI
//  AD9850 gen.dds_pulse(10, 9, 8, &SPI, 6);  //  HW SPI

uint32_t freq = 0;
uint32_t prev = 0;
uint32_t maxFreq;

void help()
{
  Serial.println();
  Serial.println("+ :  f = f + 0.01");
  Serial.println("- :  f = f - 0.01");
  Serial.println("* :  f = f * 10");
  Serial.println("/ :  f = f / 10");
  Serial.println("? :  help");
  Serial.println("R :  AD9850 reset");
  Serial.println("P :  AD9850 power down");
  Serial.println("U :  AD9850 power up");
  Serial.println();
}


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("AD985X_LIB_VERSION: \t");
  Serial.println(AD985X_LIB_VERSION);

  help();

  gen.dds_pulse.begin();
  gen.dds_pulse.powerUp();
  maxFreq = gen.dds_pulse.getMaxFrequency();
  Serial.println(maxFreq);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int c = Serial.read();
    switch (c)
    {
    case '?':
      help();
      break;
    case 'R':
      gen.dds_pulse.reset();
      freq = gen.dds_pulse.getFrequency();
      break;
    case 'P':
      gen.dds_pulse.powerDown();
      break;
    case 'U':
      gen.dds_pulse.powerUp();
      break;
    case '+':
      freq += 1;
      break;
    case '-':
      freq -= 1;
      break;
    case '*':
      freq *= 10;
      break;
    case '/':
      freq /= 10;
      break;
    }
    if (freq > maxFreq)
      freq = maxFreq;
  }

  //  UPDATE AD985X IF NEW VALUE
  if (prev != freq)
  {
    prev = freq;
    gen.dds_pulse.setFrequencyF(freq * 0.01);
    Serial.println(freq);
  }
}

//  -- END OF FILE --