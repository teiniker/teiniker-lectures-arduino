#include "Led.h"

Led redLed(7);
Led greenLed(8, true);

void setup() 
{
}

void loop() 
{
  redLed.toggle();  
  greenLed.toggle();    
  delay(1000);                       
}
