#include "LCD.h"
#include <LiquidCrystal_I2C.h>


void LCD::initWithBackLight() {
  LCD::init();
  LCD::backlight();
}

void LCD::printText(int col, int row, char text[16]) {
  LCD::setCursor(col, row);
  LCD::print(text);
}

void LCD::printUnits(int white, int black) {
  LCD::setCursor(0, 0);
  LCD::print("WHITE");
  LCD::setCursor(7, 0);
  LCD::print(white);
  LCD::setCursor(0, 1);
  LCD::print("BLACK");
  LCD::setCursor(7, 1);
  LCD::print(black);
}

void LCD::printDistance(int col, int row, long distance) {
  LCD::setCursor(col, row);
  LCD::print(distance);
  LCD::setCursor(col + 5, row);
  LCD::print("cm");
}