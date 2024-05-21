#include "Arduino.h"
#include "ServoMotor.h"
#include "Servo.h"

bool ServoMotor::validValue(byte value) {
  return value > -1 && value < 181;
}

ServoMotor::ServoMotor(byte pin, byte open, byte close) {
  this->pin = pin;
  if (validValue(open)) {
    openValue = open;
  }
  //TODO - LEARN HOW THROW EXCEPTIONS
  if (validValue(close)) {
    closeValue = close;
  }
  //TODO - LEARN HOW THROW EXCEPTIONS
}

void ServoMotor::init() {
  servo.attach(pin, 500, 2500);
}

void ServoMotor::rotateTo(int to) {
  if (validValue(to)) {
    servo.write(to);
  }
  //TODO - LEARN HOW THROW EXCEPTIONS
}

void ServoMotor::open() {
  servo.write(openValue);
}

void ServoMotor::close() {
  servo.write(closeValue);
}