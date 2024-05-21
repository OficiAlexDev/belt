#include "Arduino.h"
#include "Motor.h"

//MOTOR CONSTRUCTOR
Motor::Motor(byte pinActivator_1_2, byte enter_1, byte enter_2) {
  this->pinActivator_1_2 = pinActivator_1_2;
  this->enter_1 = enter_1;
  this->enter_2 = enter_2;
}

//WRITE ALL OUTPUTS TO MAKE H BRIDGE ACTIVE MOTOR
void Motor::rotate(int speed = 255, bool clockwise = true) {
  analogWrite(pinActivator_1_2, speed);
  digitalWrite(enter_1, clockwise ? HIGH : LOW);
  digitalWrite(enter_2, clockwise ? LOW : HIGH);
}

//DEFINE PINS IN OUTPUT MODE AND CALL ROTATE FUNCTION
void Motor::init() {
  pinMode(enter_1, OUTPUT);
  pinMode(enter_2, OUTPUT);
  pinMode(pinActivator_1_2, OUTPUT);
  Motor::rotate();
}