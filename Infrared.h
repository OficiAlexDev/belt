#ifndef Infrared_h
#define Infrared_h

#include "Arduino.h"

class Infrared {
public:
  //DEFINE ANALOG AND DIGITAL PINS
  Infrared(byte digitalPin, uint8_t analogPin);
  //DEFINE PINS MODE
  void init();
  //READ IN DIGITAL MODE
  int digital();
  //READ IN ANALOG MODE
  int analog();
private:
  byte digitalPin;
  uint8_t analogPin;
};

#endif