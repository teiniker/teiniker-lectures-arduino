#ifndef _PORT_EXTENSION_H_ 
#define _PORT_EXTENSION_H_

#include <Arduino.h>

class PortExtension
{
	public:
  		PortExtension(int latch_pin, int clock_pin, int data_pin);
  		void writeByte(uint8_t value);
  		void setBit(uint8_t bit);

  	private:
  		uint8_t _latch_pin;
  		uint8_t _clock_pin;
  		uint8_t _data_pin;
  		uint8_t _data;
  
 	 	void _update_shift_register(void);
};

#endif //_PORT_EXTENSION_H_