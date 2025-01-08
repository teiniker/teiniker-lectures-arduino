#ifndef _LED_H_    // Include guard
#define _LED_H_

#include <stdint.h>

class Led
{
    private:    // Private members (inside the class only)
        uint8_t _pin;
        bool _state;

    public:    // Public members
        // Constructor
        Led(uint8_t pin, bool state = false);    

        // Public methods
        bool state(void);
        uint8_t pin(void);

        void on(void);
        void off(void);
        void toggle(void);

    private:    // Private members 
        void _setPin();
};


#endif
