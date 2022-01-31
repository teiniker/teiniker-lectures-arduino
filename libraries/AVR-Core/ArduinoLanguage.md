# Arduino Language

Arduino language refers to the Arduino-specific features of the C/C++ language which relate 
to the AVR microcontroller and how it operates.

## Bit Manipulation

The following bit manipulation macros are defined in the `Arduino.h` header file.

* **bit(b)**\
    This macro returs the value of `2^b` where `b` is the bit number (0 to 31) as an unsigned long.
    
    _Example_: `bit(5)` returns `2^5 = 32`

* **bitClear(value, bit)**\
    This macro clears the requested `bit`, in the `value` passed, to zero and returns the resulting new value.

* **bitRead(value, bit)**\
    This macro returns a one or a zero depending on the state of the `bit` requested in the `value` passed.

* **bitSet(value, bit)**\
    This macro can be called to set a specific `bit` in a variable or `value` to a one.

* **bitWrite(value, bit, bitvalue)**\
    The purpose of this macro is to call either `bitSet()` or `bitClear()` for the appropriate `bit`, 
    in a `value` or variable, depending on wether it is to be set to a one or a zero.

* **highByte(w)**\
    This macro returns the value in the higher 8 bits of a value or variable.
    It returns a `uint8_t` which is guaranteed to be an unsigned, 8-bit value.

* **lowByte(w)**\
    This macro returns the value in the lower 8 bits of a value or variable.
    It returns a `uint8_t` which is guaranteed to be an unsigned, 8-bit value.


The following bit manipulation functions are declared in the `wiring_private.h` header file.

* **cbi(sfr, bit)**\
    The macro clears the requested bit, in the **register**, to zero.
    We cannot call this macro with a value or variable - it must be a register, as defined in the 
    `iom328p.h` file which is included indirectly by `Arduino.h`. 


## Digital I/O


* **unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)**\
  **unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L)**\
    Reads a pulse (either HIGH or LOW) on a pin. 
    For example, if `value` is `HIGH`, `pulseIn()` waits for the `pin` to go from `LOW` to `HIGH`, starts timing, then waits for the pin to go `LOW` and stops timing. 
    
    `timeout` specifies the number of microseconds to wait for the pulse to start - default is one second. 

    Returns the **length of the pulse in microseconds** or gives up and returns 0 if no complete pulse was received within the timeout.

    The timing of this function has been determined empirically and will probably show errors in longer pulses. Works on pulses from 10 microseconds to 3 minutes in length.



## Analogue I/O


## Advanced I/O


## Time


## Interrupt



## References
* [GitHub: ArduinoCore-avr/cores/arduino/](https://github.com/arduino/ArduinoCore-avr/tree/master/cores/arduino)

* Norman Dunbar. **Arduino Software Internals**. APress 2020
    * Chapter 3: Arduino Language Reference

*Egon Teiniker, 2020 - 2022, GPL v3.0* 