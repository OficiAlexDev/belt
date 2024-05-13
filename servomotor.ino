#include <Servo.h>

Servo servoRight;
Servo servoLeft;

void setupServo() {
  servoLeft.attach(9, 500, 2500);
  servoRight.attach(10, 500, 2500);
}

void activeRightServo() {
  openLeftServo();
  delay(100);
  closeRightServo();
}

void activeLeftServo() {
  openRightServo();
  delay(100);
  closeLeftServo();
}

void disableAllServos() {
  openLeftServo();
  delay(100);
  openRightServo();
}

void openLeftServo() {
  servoLeft.write(90);
}

void closeLeftServo() {
  servoLeft.write(0);
}

void openRightServo() {
  servoRight.write(90);
}

void closeRightServo() {
  servoRight.write(180);
}