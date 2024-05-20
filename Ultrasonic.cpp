#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(byte trigger, byte echo) {
  this->trigger = trigger;
  this->echo = echo;
}

void Ultrasonic::init() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

float Ultrasonic::distance() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  return 0.01723 * pulseIn(echo, HIGH);
}