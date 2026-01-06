#ifndef __DIGITAL_IO_H__
#define __DIGITAL_IO_H__

#include <Arduino.h> 

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
//	GPIO_0 = 0,
//	GPIO_1 = 1,
	GPIO_2 = 2,
	GPIO_3 = 3,
	GPIO_4 = 4,
	GPIO_5 = 5,
	GPIO_6 = 6,
	GPIO_7 = 7,
} GpioPin_t;


extern void gpio_mode( GpioPin_t pin, PinMode_t mode);
extern void gpio_write(GpioPin_t pin, PinState_t state);
extern PinState_t gpio_read(GpioPin_t pin);



#endif // __DIGITAL_IO_H__