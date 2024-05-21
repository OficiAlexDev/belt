#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

class Ultrasonic {
public:
  //DEFINE TRIGGER AND ECHO PINS
  Ultrasonic(byte trigger, byte echo);
  //DEFINE PINS MODE
  void init();
  //READ DISTANCE IN CM
  float distance();
private:
  byte trigger;
  byte echo;
};

#endif