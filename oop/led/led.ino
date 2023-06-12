#include "Led.h"

Led redLed(7);
Led greenLed(8);

void setup() 
{
}

void loop() 
{
  redLed.on();  
  greenLed.off();    
  delay(1000);                       
  
  redLed.off();  
  greenLed.on();     
  delay(1000);                       
}
