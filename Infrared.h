#ifndef Infrared_h
#define Infrared_h

#include "Arduino.h"

class Infrared {
public:
  Infrared(byte digitalPin,uint8_t analogPin);
  void init();
  int digital();
  int analog();
private:
  byte digitalPin;
  uint8_t analogPin;
};

#endif