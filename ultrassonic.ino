void setupUltrasonic() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

long readDistance() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  return 0.01723 * pulseIn(3, HIGH);
}