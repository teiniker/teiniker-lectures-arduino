#include "digital_io.h"


void gpio_mode( GpioPin_t pin, PinMode_t mode)
{
	if(mode == OUT)
	{
		DDRD |= (1 << pin);
	}
	else if(mode == IN)
	{
		DDRD &= ~(1 << pin);
		PORTD &= ~(1 << pin); // disable pull-up
	}
	else if(mode == IN_PULLUP)
	{
		DDRD &= ~(1 << pin);
		PORTD |= (1 << pin); // enable pull-up
	}
}


void gpio_write(GpioPin_t pin, PinState_t state)
{
	if(state == HI)
	{
		PORTD |= (1 << pin);
	}
	else
	{
		PORTD &= ~(1 << pin);
	}
}


PinState_t gpio_read(GpioPin_t pin)
{
	if(PIND & (1 << pin))
	{
		return HI;
	}
	else
	{
		return LO;
	}
}

