#include <Arduino.h>
#include "led.h"

Led::Led(uint8_t pin, bool state)
{
    if(pin > 1 && pin < 14)
        _pin = pin;
    else 
        _pin = 13; // on-board LED

    _state = state; 
    pinMode(_pin, OUTPUT); 
}

void Led::on(void)
{
    _state = true;
    _setPin();
}

void Led::off(void)
{
    _state = false;
    _setPin();
}

void Led::toggle(void)
{
    _state = !_state;
    _setPin();
}

void Led::_setPin(void)
{
    digitalWrite(_pin, _state);
}
