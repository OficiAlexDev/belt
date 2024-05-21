#include "Arduino.h"
#include "ServoMotor.h"
#include "Servo.h"

void ServoMotor::init(byte pin, byte open, byte close) {
  this->pin = pin;
  openValue = open;
  closeValue = close;
  servo.attach(pin, 500, 2500);
}

void ServoMotor::rotateTo(int to) {
  if (to > -1 && to < 181) {
    servo.write(to);
  }
  //TODO LEARN HOW THROW EXCEPTIONS
}

void ServoMotor::open() {
  servo.write(openValue);
}

void ServoMotor::close() {
  servo.write(closeValue);
}