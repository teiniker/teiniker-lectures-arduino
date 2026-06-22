#include "extension.h"

PortExtension::PortExtension(int latch_pin, int clock_pin, int data_pin)
{
    _latch_pin = latch_pin;
    _clock_pin = clock_pin;
    _data_pin = data_pin;
    _data = 0;

    pinMode(_latch_pin, OUTPUT);
    pinMode(_data_pin, OUTPUT);  
    pinMode(_clock_pin, OUTPUT);
    _update_shift_register();
}
  
void PortExtension::writeByte(uint8_t value)
{
    _data = value;
    _update_shift_register();
}

void PortExtension::setBit(uint8_t bit)
{
    bitSet(_data, bit);
    _update_shift_register();
}

void PortExtension::_update_shift_register(void)
{
    digitalWrite(_latch_pin, LOW);
    shiftOut(_data_pin, _clock_pin, LSBFIRST, _data);
    digitalWrite(_latch_pin, HIGH);
}