#include "Arduino.h"
#include "Motor.h"

Motor::Motor(byte pinActivator_1_2, byte enter_1, byte enter_2) {
  this->pinActivator_1_2 = pinActivator_1_2;
  this->enter_1 = enter_1;
  this->enter_2 = enter_2;
}

void Motor::rotate(int speed = 255, bool clockwise = true) {
  analogWrite(pinActivator_1_2, speed);
  digitalWrite(enter_1, clockwise ? HIGH : LOW);
  digitalWrite(enter_2, clockwise ? LOW : HIGH);
}

void Motor::init() {
  pinMode(enter_1, OUTPUT);
  pinMode(enter_2, OUTPUT);
  pinMode(pinActivator_1_2, OUTPUT);
  Motor::rotate();
}