#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor {
public:
  //MOTOR CONSTRUCTOR
  Motor(byte pinActivator_1_2, byte enter_1, byte enter_2);
  //WRITE ALL OUTPUTS TO MAKE H BRIDGE ACTIVE MOTOR
  void init();
  //DEFINE PINS IN OUTPUT MODE AND CALL ROTATE FUNCTION
  void rotate(int speed, bool clockwise);
private:
  byte pinActivator_1_2;
  byte enter_1;
  byte enter_2;
};

#endif