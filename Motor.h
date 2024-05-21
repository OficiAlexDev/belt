#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor {
public:
  //MOTOR CONSTRUCTOR
  Motor(byte pinActivator_1_2, byte enter_1, byte enter_2);
  //WRITE ALL OUTPUTS TO MAKE H BRIDGE ACTIVE MOTOR
  void init();
  //WRITING H BRIDGE OUTPUTS PINS TO MAKE  CONTROL MOTOR BY PARAMS
  void rotate(int speed, bool clockwise);
private:
  byte pinActivator_1_2;
  byte enter_1;
  byte enter_2;
};

#endif