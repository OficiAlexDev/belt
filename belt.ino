#include "LiquidCrystal_I2C.h"
#include "Motor.h"
#include "Ultrasonic.h"
#include "Infrared.h"
#include "ServoMotor.h"
#include "LCD.h"
// #include <math.h> //Math lib for in case i need use floor();

//#include <stdio.h>
//ltoa(long,char[16],10); //stdio lib for in case i need pass a long to char[] // for last param 10 means the long is in decimal base; (16 is for hex and etc.)

//TIME THE CUBE TAKES TO PASS BETWEEN INFRARED AND THE ULTRASONIC
const int TIME_INFRARED_ULTRASONIC = 120;
//TIME TO VALID IF COUNT ONLY ONE TIME PEER CUBE
const int TIME_PASS_ULTRASONIC = 400;
//INFRARED READ VALUE FROM WHITE CUBE
const int INFRARED_WHITE = 150;

//GLOBALS OBJECTS INSTANCES
Motor motor(11, 12, 13);
Ultrasonic ultrasonic(2, 3);
Infrared infrared(7, A0);
LCD lcd(0x3f, 16, 2);
ServoMotor servoLeft;
ServoMotor servoRight;
//COUTER VARIABLES
int white = 0, black = 0;
//TIME CONTROLL VARIABLES
int timeDetectUltrasonic = 0, lastUltrasonicDetect = 0, lastWhiteInfrared = 0;

void setup() {
  lcd.initWithBackLight();
  motor.init();
  ultrasonic.init();
  infrared.init();
  servoLeft.init(9, 90, 0);
  servoRight.init(10, 90, 180);
}

void loop() {
  //SAVING THE DISTANCE IN A VARIABLE TO REDUCE ULTRASONIC SENSOR USES
  int distance = ultrasonic.distance();
  //SAVING THE CURRENT TIME IN A VARIABLE
  unsigned long currentMilis = millis();

  //DEFINING LAST TIME A WHITE CUBE HAS PASSED, USING SIMPLE COMPARATIVE, CHECKING IF READED INFO BY INFRARED IS LOWER THAN WHITE CONSTANT VALUE PLUS 15 PERCENT
  if (infrared.analog() < INFRARED_WHITE * 1.15f) {
    lastWhiteInfrared = currentMilis;
  }

  //DETEC AN OBJECT
  if (distance < 10 && timeDetectUltrasonic < currentMilis - TIME_PASS_ULTRASONIC) {
    //DEFINING ULTRASONIC DETECTION TIME
    timeDetectUltrasonic = currentMilis;
    //DEFINING LAST DISTANCE
    lastUltrasonicDetect = distance;
    //ANALOG READ < 200 WE HAVE SURE IS A WHITE CUBE
    if (lastWhiteInfrared >= currentMilis - TIME_INFRARED_ULTRASONIC) {
      //CLOSE RIGHT STICK AND COUNT MORE ONE TO WHITE
      white++;
      servoLeft.open();
      delay(250);
      servoRight.close();
    } else {
      //INVERSE FOR LEFT
      black++;
      servoRight.open();
      delay(250);
      servoLeft.close();
    }
  }

  //LCD MANAGER
  lcd.clear();
  if (timeDetectUltrasonic > currentMilis - 1000) {
    lcd.printDistance(0, 1, lastUltrasonicDetect);
  } else {
    lcd.printUnits(white, black);
  }
}
