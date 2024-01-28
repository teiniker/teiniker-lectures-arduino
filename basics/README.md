# Microcontroller Programming Basics

The basic programming techniques for microcontrollers are shown using 
the **ATMega328P**. The techniques used can also easily be applied to 
other microcontrollers as well.

The microcontroller directly incorporates the **hardware components** used:

* [Serial Communication (UART)](serial/)
* [I/O Ports](io-ports/)
* [Memory](memory/)

In addition to the use of hardware components, the following 
**programming techniques** are also used in the context of microcontroller 
programming:

* [Timing and Scheduling](timing/)
* [State Machines](state-machines/)
* [Object-Oriented Programming](oop/)

Finally, the use of **libraries and frameworks** enables an abstraction 
from the concrete microcontroller - **Hardware Abstraction Layer (HAL)**. 
This makes it easy to get applications running on different boards 
implementing the same HAL API.

* [Hardware Abstraction](libraries/)
    * [Register Programming](hardware-abstraction/register-programming/io-ports/)
    * [Interrupts](hardware-abstraction/interrupts/)
    * [Port Extension (74HC595)](hardware-abstraction/port-extension/)
    * [Create Arduino Libraries](hardware-abstraction/arduino-library/)

*Egon Teiniker, 2020-2024, GPL v3.0* 
