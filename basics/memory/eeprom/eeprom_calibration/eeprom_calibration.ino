#include <EEPROM.h>

void setup() 
{
  Serial.begin(9600);    
  
  Serial.print("EEPROM size: ");
  Serial.println(EEPROM.length());
  
  EEPROM.put(0x00, 2.0);	// gain
  EEPROM.put(0x04, -5.0); 	// offset
}

void loop() 
{
  float gain; 
  float offset; 
  EEPROM.get(0x00, gain);
  EEPROM.get(0x04, offset);
  
  uint16_t adc = analogRead(A0);
  float value = adc * 5.0/1023.0;
  value = value * gain + offset;	
  
  Serial.println(value);
  
  delay(100);                             
}
