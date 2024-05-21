#ifndef LCD_h
#define LCD_h

#include "Arduino.h"
#include "LiquidCrystal_I2C.h"

//USING LiquidCrystal_I2C LIB CLASS AS INHERITANCE AND CALLING CONSTRUCTOR BASE TO SETUP LCD PROPERTIES
class LCD : public LiquidCrystal_I2C {
public:
  LCD(uint8_t adress, uint8_t cols, uint8_t rows)
    : LiquidCrystal_I2C(adress, cols, rows) {}
  //MERGE INIT AND BACKLIGHT METHODS
  void initWithBackLight();
  //USEFUL PRINTERS FOR THIS PROJECT
  void printText(int col, int row, char text[16]);
  void printUnits(int white, int black);
  void printDistance(int col, int row, long distance);
private:
};

#endif