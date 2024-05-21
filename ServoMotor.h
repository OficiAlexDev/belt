#ifndef ServoMotor_h
#define ServoMotor_h

#include "Arduino.h"
#include <Servo.h>

class ServoMotor {
public:
  void init(byte pin, byte open, byte close);
  //DYNAMIC ROTATE BY CUSTOM VALUE
  void rotateTo(int to);
  //OPEN BY VALUE SETTED IN INIT
  void open();
  //CLOSE BY VALUE SETTED IN INIT
  void close();
private:
  byte pin;
  byte openValue;
  byte closeValue;
  Servo servo;
};

#endif