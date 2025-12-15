
typedef enum 
{
	IN = 0,
	OUT = 1,
	IN_PULLUP = 2
} PinMode_t;


typedef enum 
{
	LO = 0,
	HI = 1
} PinState_t;


typedef enum 
{
	GPIO_0 = 0,
	GPIO_1 = 1,
	GPIO_2 = 2,
	GPIO_3 = 3,
	GPIO_4 = 4,
	GPIO_5 = 5,
	GPIO_6 = 6,
	GPIO_7 = 7,
} GpioPin_t;


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

void setup()
{
		gpio_mode(GPIO_2, OUT);   	// pin 2 => output
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
