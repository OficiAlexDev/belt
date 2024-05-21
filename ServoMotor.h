#ifndef ServoMotor_h
#define ServoMotor_h

#include "Arduino.h"
#include <Servo.h>

class ServoMotor {
public:
  void init(byte pin, byte open, byte close);
  void rotateTo(int to);
  void open();
  void close();
private:
  byte pin;
  byte openValue;
  byte closeValue;
  Servo servo;
};

#endif