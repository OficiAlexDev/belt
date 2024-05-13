void setupMotor() {
  //PIN MODE FOR H BRIDGE
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  motorRotate();
}

void motorRotate() {
  analogWrite(11, 255);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
}

void motorRotateReverse() {
  analogWrite(11, 255);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
}