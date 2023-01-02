# EEPROM Data Memory

The ATmega328P contains 1 Kbyte of data EEPROM memory. 

It is organized as a separate data space, in which single bytes can be read and written. 
The EEPROM has an endurance of at least 100,000 write/erase cycles. 

_Example_: [Arduino EEPROM (get, put)](https://www.tinkercad.com/things/hYf9OOX57nT)



## Arduino Library Functions

The `EEPROM.h` header file declares the following operation which can be used to access the 
integrated EEPROM.

* **uint8_t read(int address)**\
Reads a byte from the EEPROM. Locations that have never been written to have the value of 255.

The parameter `address` specifies the location to read from, starting from 0.

Returns the value stored in the given location.

* **void write(int address, uint8_t value)**\
Write a byte to the EEPROM.
An EEPROM write takes 3.3 ms to complete. 
The EEPROM memory has a specified life of 100,000 write/erase cycles, so you may need to 
be careful about how often you write to it.

The parameter `address` specifies the location to read from, starting from 0. 
The second parameter is the `value` to write, from 0 to 255.


* **void update(int address, uint8_t value)**\
Write a byte to the EEPROM. **The value is written only if differs from the one already saved** at the same address.

The parameter `address` specifies the location to read from, starting from 0. 
The second parameter is the `value` to write, from 0 to 255.


* **uint16_t length(void)**\
This operation returns an unsigned int containing the number of cells in the EEPROM.


## References

* [YouTube (DroneBot Workshop): Using EEPROM with Arduino - Internal & External](https://youtu.be/ShqvATqXA7g)

* [A guide to EEPROM](https://docs.arduino.cc/learn/programming/eeprom-guide)

* [EEPROM Library V2.0 for Arduino](https://github.com/arduino/ArduinoCore-avr/tree/master/libraries/EEPROM)

*Egon Teiniker, 2020-2023, GPL v3.0* 
