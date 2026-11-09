# Embedded Programming with Arduino


## Computer Architectures

The basic operational design of a computer system is called architecture.
In the following sections the basic mechanisms and components of computer 
architectures are examined.

* [Introduction](computer-architectures/introduction/)
    
* [Combinatorial Logic](computer-architectures/combinatorial-logic/)

* [Sequential Logic](computer-architectures/sequential-logic/)

* [Processor Unit](computer-architectures/processor-unit/README.md)

* [Microcontrollers](computer-architectures/microcontrollers/README.md)
    - Example: [ATmega328p](computer-architectures/microcontroller/atmega328p/)
    - Example: [ESP32-C3](computer-architectures/microcontroller/esp32-c3/)
    - Microcontroller Boards
        - [Arduino UNO R3](boards/avr/uno-r3/)
        - [Arduino Nano](boards/avr/nano/)
        - [XIAO ESP32C3](boards/esp32/XIAO-ESP32C3/)

* [Specialized Processors](computer-architectures/specialized-processors/README.md)


## Embedded Programming 

This section provides an introduction to embedded programming using 
the **Arduino Uno** and the **XIAO ESP32C3** microcontroller boards. 
While Arduino Uno uses an 8 bit (ATMega328P) microcontroller, 
the XIAO ESP32C3 uses a 32 bit (RISC V) core.

* [Setup](embedded-programming/setup/)

* [Microcontroller Peripherals](embedded-programming/peripherals/)

* [Sensors and Actuators](embedded-programming/sensors-and-actuators/)

* [Hardware Abstraction](embedded-programming/hardware-abstraction/)

* [Timing and Scheduling](embedded-programming/scheduling/)

* [FreeRTOS](embedded-programming/freertos/)

* [Programming Techniques](embedded-programming/programming-techniques/)

* Arduino Core Framework
    - [AVR](arduino-core/avr/)
    - [ESP32](arduino-core/esp32/)


## Configuration Management for Embedded Systems

* Introduction
    - [VS Code + PlatformIO](configuration-management/PlatformIO/README.md)
    - [PlatformIO CLI](configuration-management/PlatformIO-CLI/README.md)

* Build Automation
    - [Project Layout](configuration-management/building/project-layout/README.md)
        - Example (Uno): [hello-blink](configuration-management/building/project-layout/arduino-uno/hello-blink/)
        - Example (Uno): [hello-serial](configuration-management/building/project-layout/arduino-uno/hello-serial/)
        - Example (XIAO ESP32C3): [hello-blink](configuration-management/building/project-layout/xiao-esp32c3/hello-blink/)
        - Example (XIAO ESP32C3): [hello-serial](configuration-management/building/project-layout/xiao-esp32c3/hello-serial/)

    - [Library Management](configuration-management/building/library-management/introduction/README.md)
        - Example (Uno): [blink_timer1](configuration-management/building/library-management/arduino-uno/blink_timer1/)

* Debugging 
    - [ArduinoLog](configuration-management/debugging/logging/ArduinoLog/README.md)
    
    - Arduino Uno 
        - [Introduction](configuration-management/debugging/introduction/README.md)
        - Example (Uno): [hello-blink](configuration-management/debugging/arduino-uno/hello-blink/)

    - XIAO ESP32C3
        - [Introduction](configuration-management/debugging/xiao-esp32c3/README.md)
        - Example (XIAO ESP32C3): [hello-blink](configuration-management/debugging/xiao-esp32c3/hello-blink/)
    
* Test Automation
    - [Introduction](configuration-management/testing/introduction/README.md)
    - Example (Uno): [integer-types](configuration-management/testing/arduino-uno/integer-types/)
    - Example (XIAO ESP32C3): [integer-types](configuration-management/testing/xiao-esp32c3/integer-types/)
    - Example (XIAO ESP32C3): [base64-encoding](configuration-management/testing/xiao-esp32c3/base64-encoding/)
  

## Use of Coding Agents
This repository was developed using coding agents to assist with design 
discussions, implementation, and documentation. 
All materials have been manually reviewed and verified.


## References

* Computer Architectures
    * Randall Hyde. **Writing Great Code / Volume 1: Understanding the Machine**. No Starch Press, 2020
        * Chapter 8: Boolean Logic and Digital Design
    * M. Morris Mano. **Computer Engineering – Hardware Design**. Prentice Hall, 1988
    * Andrew S. Tanenbaum. **Structured Computer Organization**. Pearson Education, International Edition, 2013
    * Daniele Lacamera. **Embedded Systems Architecture**. Packt Publishing, 2023.

* Embedded Programming
    * Michael Margolis, Brian Jepson, Nicholas Robert Weldin. **Arduino Cookbook**. O'Reilly, 2020
    * Norman Dunbar. **Arduino Software Internals**. APress, 2020
    * Warren Gay. **FreeRTOS for ESP32-Arduino: Practical Multitasking Fundamentals**. Elektor International, 2020

* Configuration Management
    * [PlatformIO](https://platformio.org/)

*Egon Teiniker, 2020-2026, GPL v3.0* 
