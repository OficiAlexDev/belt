#include "Arduino.h"
#include "ServoMotor.h"
#include <Servo.h>

void ServoMotor::init(byte pin) {
  this->pin = pin;
  servo.attach(pin, 500, 2500);
}

void ServoMotor::to0() {
  servo.write(0);
}

void ServoMotor::to90() {
  servo.write(90);
}

void ServoMotor::to180() {
  servo.write(180);
}