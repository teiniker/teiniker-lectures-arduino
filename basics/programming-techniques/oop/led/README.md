# Example: LED Class

Let's walk through an example of a simple LED class. This class will have 
a few methods to turn the LED on and off, and to check if the LED is on 
or off.

## led.h

* **Include Guard** 

    ```C++
    #ifndef _LED_H_    // If _LED_H_ is not defined...
    #define _LED_H_    // ...then define it.    

    // ...

    #endif
    ```

    Prevents multiple inclusions of the same header file:

    * When the compiler processes this file the first time, `_LED_H_` is not yet 
        defined, so it defines it.
    * If this file is included again in another file, `_LED_H_` will already be 
        defined, and the contents will be skipped—preventing redefinition errors.

* **Library Includes** 

    ```C++
    #include <stdint.h>
    ```

    Provides fixed-width integer types like uint8_t (an unsigned 8-bit integer).
    Especially useful in microcontroller or embedded contexts where precise control 
    over bit sizes is important.

* **Class Declaration**
    ```C++
    class Led
    {
        //...
    };
    ```

    Declares a `Led` class.
    The ´Led´ class represents a single LED, tied to a specific pin, with methods 
    to control its on/off state.

* **Private Members**
    ```C++
    private:
        uint8_t _pin;
        bool _state;
    ```

    These members are private, meaning they’re only accessible from within the 
    `Led` class itself (including its methods).

    * `uint8_t _pin`
        * Stores the microcontroller pin number on which the LED is connected.
        * The `uint8_t` type ensures it’s an 8-bit unsigned integer.

    * `bool _state`
        * Stores whether the LED is currently on (true) or off (false).


* **Public Members**
    ```C++
    public:
        Led(uint8_t pin, bool state = false);
        
        bool state(void);
        uint8_t pin(void);

        void on(void);
        void off(void);
        void toggle(void);
    ```

    * Constructor: `Led(uint8_t pin, bool state = false);`
        * Initializes the LED with a pin number and an optional initial state.
        * If no state is provided, the LED is off by default.
        * This ensures when you create an `Led` object, you assign the correct 
            pin and set the initial LED state.

    * Accessor methods:
        ```C++
        bool state(void);
        uint8_t pin(void);
        ```

        * `state()` returns the current LED state (true for on, false for off).
        * `pin()` returns the pin number the LED is associated with.

    * Control Methods:
        ```C++
        void on(void);
        void off(void);
        void toggle(void);
        ```

        * `on()` sets _state to true (LED on).
        * `off()` sets _state to false (LED off).
        * `toggle()` flips _state: if on, turn it off; if off, turn it on.
        * These methods would also normally call a helper function (like `_setPin()`) 
            to write the state to the actual hardware pin.

* **Private Methods** 
    ```C++
    private:
        void _setPin();
    ```

    * A helper function that handles the low-level operation of writing the LED’s 
        state to the physical pin.
    * Because it’s private, only other methods of `Led` can call `_setPin();` the 
        user of the Led class cannot call this method directly.

This structure is common in embedded C++ programming, where each peripheral or component 
(LED, button, sensor, etc.) is represented by a class that **encapsulates the necessary 
hardware details and provides a clean interface** for the rest of the code to interact with.


## led.cpp 

This is the corresponding C++ source file for the `Led` class declared in `led.h`. 

The primary purpose is to define how each method in the `Led` class behaves at 
runtime—especially how it interacts with Arduino hardware.

* **Include the Header File**
    ```C++
    #include "led.h"
    ```

    * This includes the `led.h` file, which contains the class declaration

* **Constructor**
    ```C++
    Led::Led(uint8_t pin, bool state)
    {
        if(pin > 1 && pin < 14)
            _pin = pin;
        else 
            _pin = 13; 

        _state = state; 
        pinMode(_pin, OUTPUT);
    }
    ```

    * Pin validation: 
        Checks if the pin is between 2 and 13 (inclusive). If it is, `_pin` is set 
        to the given pin.
        Otherwise, it defaults `_pin` to 13, which is often the built-in LED pin on 
        many Arduino boards.

    * Set LED state: 
        Stores the initial LED state (true for ON, false for OFF) in `_state`.

* **bool Led::state(void)**
    ```C++
    bool Led::state(void)
    {
        return _state;
    }
    ```

    * Returns the LED’s current state (true = ON, false = OFF).
    * This is a getter method that simply exposes the private `_state`.

* **uint8_t Led::pin(void)**
    ```C++
    uint8_t Led::pin(void)
    {
        return _pin;
    }
    ```

    *  Returns the pin number currently assigned to the LED.
    * Another getter method, this time for the private `_pin`.


* **void Led::on(void)**
    ```C++
    void Led::on(void)
    {
        _state = true;
        _setPin();
    }  
    ```

    * Turns the LED on.
    * Sets `_state` to true and then calls `_setPin()` to apply this state to the 
        hardware pin.

* **void Led::off(void)**
    ```C++
    void Led::off(void)
    {
        _state = false;
        _setPin();
    }    
    ```

    * Turns the LED off.
    * Sets `_state` to false, then calls `_setPin()` to apply this to the hardware pin.

* **void Led::toggle(void)**
    ```C++
    void Led::toggle(void)
    {
        _state = !_state;
        _setPin();
    }
    ```

    * Flips the LED state from OFF to ON or from ON to OFF.
    * Uses the `!` operator on `_state` to invert it, then calls `_setPin()` so the change 
        is reflected on the hardware.

* **void Led::_setPin(void)**
    ```C++
    void Led::_setPin(void)
    {
        digitalWrite(_pin, _state);
    }
    ```

    * Private helper function to write the current `_state` to the LED pin.
    * Calls `digitalWrite(_pin, _state)` to set the pin voltage HIGH (true) or LOW (false).
    * This is private because users of the `Led` class call the higher-level methods (on(), 
        off(), toggle()) instead of directly messing with the pin.

This is a simple example of an LED class in C++ that can be used to control an LED
connected to an Arduino or similar microcontroller. It demonstrates the principles
of encapsulation, abstraction, and object-oriented design in embedded systems programming.

*Egon Teiniker, 2020-2025, GPL v3.0* 
