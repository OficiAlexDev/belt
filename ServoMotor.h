#ifndef ServoMotor_h
#define ServoMotor_h

#include "Arduino.h"
#include <Servo.h>

class ServoMotor {
public:
  //DEFINE SERVO SIGNAL PIN AND VALUES TO OPEN AND CLOSE
  ServoMotor(byte pin, byte open, byte close);
  //ATTACH SERVO
  void init();
  //DYNAMIC ROTATE BY CUSTOM VALUE
  void rotateTo(int to);
  //OPEN BY VALUE SETTED IN INIT
  void open();
  //CLOSE BY VALUE SETTED IN INIT
  void close();
private:
  //CHECKS IF IS VALID VALUE (BETWEEN 0 AND 180)
  bool validValue(byte value);
  byte pin;
  byte openValue;
  byte closeValue;
  Servo servo;
};

#endif