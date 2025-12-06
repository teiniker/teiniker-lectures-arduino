#include <EEPROM.h>

void setup() 
{
  Serial.begin(115200);    
  
  Serial.print("EEPROM size: ");
  Serial.println(EEPROM.length());
  
  EEPROM.put(0x00, 2.0);	  // gain
  EEPROM.put(0x04, -5.0); 	// offset
}

void loop() 
{
 
  float value;	
  
  // TODO: implementation goes here
  
  Serial.println(value);
  
  delay(100);                             
}
