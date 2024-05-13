#include <LiquidCrystal_I2C.h>
//#include <stdio.h>
//ltoa(long,char[16],10); // 10 means the long is in decimal base; (16 is for hex and etc.)
LiquidCrystal_I2C lcd(0x3f, 16, 2);

void setupLCD() {
  lcd.init();
  lcd.backlight();
}

void clearLCD() {
  lcd.clear();
}

void printTextLCD(int col, int row, char text[16]) {
  lcd.setCursor(col, row);
  lcd.print(text);
}

void printDistanceLCD(int col, int row, long distance) {
  lcd.setCursor(col, row);
  lcd.print(distance);
  lcd.setCursor(col + 5, row);
  lcd.print("cm");
}