
#include "digital_io.h"

void setup()
{
	gpio_mode(GPIO_2, OUT);   		// pin 2 => output
	gpio_mode(GPIO_4, IN);  		// pin 4 => input
}

void loop()
{
    PinState_t state = gpio_read(GPIO_4);
  
  	if(state == HI)
  		gpio_write(GPIO_2, HI);
	else
    	gpio_write(GPIO_2, LO);
}
