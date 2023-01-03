#include <EEPROM.h>

void setup() 
{
  Serial.begin(9600);    
  
  Serial.print("EEPROM size: ");
  Serial.println(EEPROM.length());
  
  // Write bytes into EEPROM
  int address = 0x0000;
  for(int i=0; i<=0xf; i++)
  {
     EEPROM.write(address+i, i); 
  }
  
  // Read bytes from EEPROM
  for(int i=0; i<=0xf; i++)
  {
     uint8_t byte;
     byte = EEPROM.read(address+i); 
  	 Serial.println(byte, HEX);
  }
  
  
  // Write bytes into EEPROM (using index operator[])
  for(int i=0; i<=0xf; i++)
  {
     EEPROM[address+i] = 0xf - i; 
  }
  
  // Read bytes from EEPROM (using index operator[])
  for(int i=0; i<=0xf; i++)
  {
     uint8_t byte;
     byte = EEPROM[address+i]; 
  	 Serial.println(byte, HEX);
  }
}

void loop() 
{
}
