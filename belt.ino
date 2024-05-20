#include <LiquidCrystal_I2C.h>
#include "Motor.h"
#include "Ultrasonic.h"
#include "Infrared.h"
#include "ServoMotor.h"

Motor motor(11, 12, 13);
Ultrasonic ultrasonic(2, 3);
Infrared infrared(7, A0);
//RIHT CLOSE IN 180
//LEFT CLOSE IN 0
//ALL OPEN IN 90
ServoMotor servoLeft;
ServoMotor servoRight;

int white = 0, black = 0;

void setup() {
  motor.init();
  ultrasonic.init();
  infrared.init();
  servoLeft.init(9);
  servoLeft.init(10);
}

void loop() {
  int distance = ultrasonic.distance();

  // lcd.clear();
  // lcd.printText(0, 0, "Ola!");
  // lcd.printDistance(0, 1, distance);

  if (distance < 200) {
    //IF TIME IS NOT ENOUGH, MAYBE REDUCE SPEED AND MAKE FASTER AGAIN AFTER DROP ITEM????
    if (infrared.digital() == 0) {
      servoLeft.to0();
      white++;
    } else {
      servoRight.to180();
      black++;
    }
  } else {
    servoLeft.to90();
    delay(180);
    servoRight.to90();
  }
}