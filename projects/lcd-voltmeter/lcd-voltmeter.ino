#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte progress[][8] =
{ 
  { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
  { B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000},
  { B11000, B11000, B11000, B11000, B11000, B11000, B11000, B11000},
  { B11100, B11100, B11100, B11100, B11100, B11100, B11100, B11100},
  { B11110, B11110, B11110, B11110, B11110, B11110, B11110, B11110},
  { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111}
};

void setup() 
{
	for(uint8_t i=0; i<6; i++)
  		lcd.createChar(i, progress[i]);
    lcd.begin(16, 2);
}

void print_bar(uint8_t x, uint8_t y, int value)
{
  	// value 0..100 => 0 - 25 pixel
  	uint8_t pixel = value*25/100;
  	uint8_t blocks = pixel/5;
    uint8_t last = pixel%5;
	
  	lcd.setCursor(x,y);
  	for(uint8_t i=0; i<blocks; i++)
		lcd.write((uint8_t)5);
  	lcd.write((uint8_t)last);
}

void loop() 
{
 	uint16_t adc1_value = analogRead(A0); // 0 ... 1023
 	uint8_t bar1_value = map(adc1_value, 0, 1023, 0, 100);
  	float voltage1 = adc1_value/1023.0*5.0;

  	uint16_t adc2_value = analogRead(A1); // 0 ... 1023
 	uint8_t bar2_value = map(adc2_value, 0, 1023, 0, 100);
  	float voltage2 = adc2_value/1023.0*5.0;
  
	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("CH1:");
  	lcd.print(voltage1, 3);
  	lcd.print("V");
  	print_bar(11,0, bar1_value);

    lcd.setCursor(0,1);
  	lcd.print("CH2:");
  	lcd.print(voltage2, 3);
  	lcd.print("V");
  	print_bar(11,1, bar2_value);
 
  	delay(500);
}