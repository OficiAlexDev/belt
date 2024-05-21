#include <LiquidCrystal_I2C.h>
#include "Motor.h"
#include "Ultrasonic.h"
#include "Infrared.h"
#include "ServoMotor.h"
#include "LCD.h"
// #include <math.h> //Math lib for in case i need use floor();

//#include <stdio.h>
//ltoa(long,char[16],10); //stdio lib for in case i need pass a long to char[] // for last param 10 means the long is in decimal base; (16 is for hex and etc.)

Motor motor(11, 12, 13);
Ultrasonic ultrasonic(2, 3);
Infrared infrared(7, A0);
LCD lcd(0x3f, 16, 2);
ServoMotor servoLeft;
ServoMotor servoRight;

int white = 0, black = 0;

void setup() {
  lcd.initWithBackLight();
  motor.init();
  ultrasonic.init();
  infrared.init();
  servoLeft.init(9, 90, 0);
  servoRight.init(10, 90, 180);
}

int timeDetectUltrasonic = 0;
int lastUltrasonicDistance = 0;
int timeDetectInfrared = 0;

void loop() {
  int distance = ultrasonic.distance();
  unsigned long currentMilis = millis();

  //DETEC AN OBJECT
  if (distance < 10 && lastUltrasonicDistance < currentMilis - 300) {
    timeDetectUltrasonic = currentMilis;
    lastUltrasonicDistance = distance;
    //ANALOG READ < 200 WE HAVE SURE IS A WHITE CUBE
    if (infrared.analog() < 200) {
      //CLOSE RIGHT STICK AND COUNT MORE ONE TO WHITE
      servoLeft.open();
      delay(250);
      servoRight.close();
      white++;
    } else {
      //INVERSE FOR LEFT
      servoRight.open();
      delay(250);
      servoLeft.close();
      black++;
    }
  }

  //LCD MANAGER
  lcd.clear();
  if (timeDetectUltrasonic > currentMilis - 1000) {
    lcd.printDistance(0, 1, lastUltrasonicDistance);
  } else {
    lcd.printUnits(white, black);
  }
}
