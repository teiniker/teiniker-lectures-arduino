#include <LiquidCrystal.h>

// LCD wiring
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4; 
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte happy[8] =
{
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

void setup() 
{
    lcd.createChar(0, happy);
    lcd.begin(16, 2);
  
  	lcd.clear();
  	uint8_t custom_char = 0;
	lcd.write(custom_char);
}

void loop() 
{
  	// do nothing
}
