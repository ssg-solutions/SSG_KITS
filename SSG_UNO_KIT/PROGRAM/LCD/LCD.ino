//CONNECT SDA & SCL TO LCD DISPLAY
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{

  lcd.init();


  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("SSG EMBEDDED ");
  lcd.setCursor(4,1);
  lcd.print("SOLUTIONS ");
}

void loop()
{
}
