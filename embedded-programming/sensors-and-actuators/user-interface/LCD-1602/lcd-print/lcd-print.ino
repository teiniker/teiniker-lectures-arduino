#include <LiquidCrystal.h>

// LCD wiring
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4; 
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
    lcd.begin(16, 2);
    lcd.print("Hello, world!");
}

void loop() 
{
    lcd.setCursor(0, 1);
    lcd.print(millis() / 1000);
}
