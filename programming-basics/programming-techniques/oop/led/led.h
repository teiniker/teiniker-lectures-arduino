#ifndef _LED_H_ 
#define _LED_H_

#include <stdint.h>

class Led
{
    private:    
        uint8_t _pin;
        bool _state;

    public:    
        Led(uint8_t pin, bool state = false);    

        bool state(void);
        uint8_t pin(void);

        void on(void);
        void off(void);
        void toggle(void);

    private:    
        void _setPin();
};


#endif
