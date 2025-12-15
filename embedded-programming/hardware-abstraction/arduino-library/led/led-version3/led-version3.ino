#include <led.h>

Led led(13);

void setup() 
{
}

void loop() 
{
  led.toggle();  
  delay(250);                       
}
