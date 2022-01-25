# Arduino Language

Arduino language refers to the Arduino-specific features of the C/C++ language which relate 
to the AVR microcontroller and how it operates.

## Bit Manipulation

The following bit manipulation functions and macros are declared in the `Arduino.h` and `wiring_private.h`
header files.

* **bit(b)**\
    The macro returs the value of `2^b` where `b` is the bit number (0 to 31) as an unsigned long.
    
    _Example_: `bit(5)` returns `2^5 = 32`

* **bitClear(value, bit)**\
    The macro cears the requested `bit`, in the `value` passed, to zero and returns the resulting new value.


## Digital I/O


## Analogue I/O


## Advanced I/O


## Time


## Interrupt



## References
* [GitHub: ArduinoCore-avr/cores/arduino/](https://github.com/arduino/ArduinoCore-avr/tree/master/cores/arduino)

* Norman Dunbar. **Arduino Software Internals**. APress 2020
    * Chapter 3: Arduino Language Reference

*Egon Teiniker, 2020 - 2022, GPL v3.0* 