int white = 0, black = 0;

void setup() {
  setupMotor();
  setupLCD();
  setupServo();
  setupServo();
  setupInfrared();
  setupUltrasonic();
}

void loop() {
  int distance = readDistance();

  clearLCD();

  printTextLCD(0, 0, "Ola!");
  printDistanceLCD(0, 1, distance);

  if (distance < 200) {
    //IF TIME IS NOT ENOUGH, MAYBE REDUCE SPEED AND MAKE FASTER AGAIN AFTER DROP ITEM????
    if (readInfrared() == 0) {
      activeLeftServo();
      white++;
    } else {
      activeRightServo();
      black++;
    }
  } else {
    disableAllServos();
  }
}