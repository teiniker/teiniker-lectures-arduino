# Arduino Core Framework

The Arduino Core Framework is the **foundation of the Arduino ecosystem**, 
providing the essential functionality and abstractions required to write 
and run code on a variety of microcontroller platforms supported by Arduino. 

It acts as a **bridge between the hardware-specific details of a microcontroller 
and the user-friendly APIs** that developers use in Arduino sketches.

Concepts of the Arduino Core Framework:

* **Platform Independence**: While the hardware capabilities of different 
    microcontrollers vary widely, the Core Framework standardizes interactions, 
    such as digital/analog I/O, timers, interrupts, and communication protocols.

* **Layered Architecture**: The Arduino Core sits between the hardware abstraction 
    layer (HAL) of a specific microcontroller and the high-level Arduino API 
    exposed to users.

* **Extensibility**: It supports various microcontroller families (e.g., AVR, 
    ESP32, Pi Pico) by allowing board manufacturers to provide their own 
    hardware-specific implementations of the Core.

The **Arduino Core** is a set of configurations and code libraries that 
realizes an hardware abstraction layer commonly used to program and interact 
with a wide range of Arduino boards. 

_Examples:_ [Arduino Boards](https://www.arduino.cc/en/hardware) 

It includes definitions for the various I/O functions, as well as the 
implementation of the **Arduino language** (a set of C/C++ functions) that 
simplifies programming for these devices. 


## Sketch Programming Model 

The Arduino Core Framework also implements the **main() function** to enable 
the familiar programming model of an Arduino Sketch.

_Example_: Programming model of an Arduino Sketch

```C++
void setup()
{
    // Executed only once
}

void loop()
{
    // Executed for ever
}
```

Here we can see how the **main() function** is implemented in the AVR Arduino 
Core Framework:

```C++
int main(void)
{
	init();
	initVariant();
#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}
```

After various initializations, the `setup()` function is called, then the 
`loop()` function is executed in an infinite loop.


## Core Libraries

The core provides essential support for standard Arduino functions like 
`digitalRead()`, `digitalWrite()`, and `analogRead()`, making it easier 
for developers to develop projects involving sensors, motors, and other 
peripherals. 

* [Arduino AVR Code](https://github.com/arduino/ArduinoCore-avr)

* [Arduino ESP32 Core](https://github.com/espressif/arduino-esp32)

* [Arduino Pi Pico Core](https://github.com/earlephilhower/arduino-pico)


## Arduino AVR Core

This Arduino AVR Core GitHib repository contains the source code and 
configuration files of the **Arduino AVR Boards platform**.

* [Arduino.h](ArduinoHeaderFile.md)

* [Arduino Language](ArduinoLanguage.md)


  
## References

* [GitHub: Arduino AVR Core](https://github.com/arduino/ArduinoCore-avr)

* Norman Dunbar. **Arduino Software Internals**. APress 2020

*Egon Teiniker, 2020-2025, GPL v3.0* 
