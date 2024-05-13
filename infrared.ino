void setupInfrared() {
  pinMode(7, INPUT);
}

int readInfrared() {
  return digitalRead(7);
}