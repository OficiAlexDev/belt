#include "LiquidCrystal_I2C.h"
#include "Motor.h"
#include "Ultrasonic.h"
#include "Infrared.h"
#include "ServoMotor.h"
#include "LCD.h"
#include <math.h>  //Math lib for in case i need use floor();

#include <stdio.h> 
//ltoa(long,char[16],10); //stdio lib for in case i need pass a long to char[] // for last param 10 means the long is in decimal base; (16 is for hex and etc.)
 

//MIN DISTANCE IN CM
const int MIN_DISTANCE = 12;
//TIME THE SERVO TAKES TO OPEN, TO NOT CLOSE ONE ABOVE THE OTHER
const int TIME_SERVO_OPEN = 200;
//TIME THE CUBE TAKES TO PASS BETWEEN INFRARED AND THE ULTRASONIC
const int TIME_INFRARED_ULTRASONIC = 450;
//TIME TO VALID IF COUNT ONLY ONE TIME PEER CUBE
const int TIME_PASS_ULTRASONIC = 400;
//INFRARED READ VALUE FROM WHITE CUBE
const int INFRARED_WHITE = 33;

//GLOBALS OBJECTS INSTANCES
Motor motor(11, 12, 13);
Ultrasonic ultrasonic(2, 3);
Infrared infrared(7, A0);
LCD lcd(0x3f, 16, 2);
ServoMotor servoLeft(9, 90, 2);
ServoMotor servoRight(10, 90, 178);
//COUTER VARIABLES
int white = 0, black = 0;
//TIME CONTROLL VARIABLES
int timeDetectUltrasonic = 0, lastUltrasonicDetect = 0, lastWhiteInfrared = 0;

void setup() {
  Serial.begin(9600);
  lcd.initWithBackLight();
  motor.init();
  ultrasonic.init();
  infrared.init();
  servoLeft.init();
  servoRight.init();
  //HERE WE PRESUME ONE OF THE SERVOS IS ALREADY OPEN, SO ONE WILL NOT CRASH AT THE OTHER
  servoLeft.open();
  servoRight.open();
}

void loop() {
  // Serial.println(infrared.analog());
  // defaultLogic();
  logicWithDelay();
}

void logicWithDelay() {
  int distance = ultrasonic.distance();
  if (infrared.analog() < INFRARED_WHITE * 1.05f) {
    servoLeft.open();
    delay(TIME_SERVO_OPEN);
    servoRight.close();
    white++;
    delay(450);
  } else if (distance < MIN_DISTANCE) {
    servoRight.open();
    delay(TIME_SERVO_OPEN);
    servoLeft.close();
    black++;
    delay(450);
  }
  lcd.printUnits(white, black);
}

//THIS IS UNSTABLE - IT WORKS FOR A FEW SECONDS AND THEN STOP
void defaultLogic() {
  //SAVING THE CURRENT TIME IN A VARIABLE
  unsigned long currentMilis = millis();
  //SAVING THE DISTANCE IN A VARIABLE TO REDUCE ULTRASONIC SENSOR USES
  int distance = ultrasonic.distance();

  //DEFINING LAST TIME A WHITE CUBE HAS PASSED, USING SIMPLE COMPARATIVE, CHECKING IF READED INFO BY INFRARED IS LOWER THAN WHITE CONSTANT VALUE PLUS 15 PERCENT
  if (infrared.analog() < INFRARED_WHITE * 1.25f && lastWhiteInfrared <= currentMilis - 500) {
    lastWhiteInfrared = currentMilis;
    servoLeft.open();
    delay(TIME_SERVO_OPEN);
    servoRight.close();
    white++;
  } else if (distance < MIN_DISTANCE && lastUltrasonicDetect <= currentMilis - 500) {
    timeDetectUltrasonic = currentMilis;
    servoRight.open();
    delay(TIME_SERVO_OPEN);
    servoLeft.close();
    black++;
  }

  if (int(floor(currentMilis / 1000)) % 2 == 0) {
    lcd.clear();
    //TAKES 1 SECOND TO SHOW DISTANCE
    if (timeDetectUltrasonic > currentMilis - 1500) {
      lcd.printDistance(0, 1, lastUltrasonicDetect);
    } else {
      lcd.printUnits(white, black);
    }
  }
}