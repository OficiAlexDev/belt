#include "Arduino.h"
#include "Infrared.h"

Infrared::Infrared(byte digitalPin, uint8_t analogPin) {
  this->digitalPin = digitalPin;
  this->analogPin = analogPin;
}

void Infrared::init() {
  pinMode(digitalPin, INPUT);
  pinMode(analogPin, INPUT);
}

int Infrared::digital() {
  return digitalRead(digitalPin);
}

int Infrared::analog() {
  return analogRead(analogPin);
}