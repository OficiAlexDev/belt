#ifndef ServoMotor_h
#define ServoMotor_h

#include "Arduino.h"
#include <Servo.h>

class ServoMotor {
public:
  void init(byte pin);
  void to0();
  void to90();
  void to180();
private:
  byte pin;
  Servo servo;
};

#endif