#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

class Ultrasonic {
public:
  Ultrasonic(byte trigger,byte echo);
  void init();
  float distance();
private:
  byte trigger;
  byte echo;
};

#endif