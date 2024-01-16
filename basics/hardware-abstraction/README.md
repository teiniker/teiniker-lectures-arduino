# Hardware Abstraction 

Hardware abstraction is a concept in computing and software engineering that 
involves **creating an abstraction layer between the software** (like an 
operating system or an application) **and the physical hardware** of a computer 
system. This abstraction layer allows software to interact with the hardware 
in a general or simplified way, rather than needing to directly manage the details 
and complexities of the hardware.


Without hardware abstraction, every application would have to be programmed 
down to the register level.
This is not only tedious, but also reduces the reusability of the application 
for different boards.

_Example:_ Register Programming - [IO Ports](register-programming/io-ports/)


By abstracting the hardware, application developers don't 
need to write code for each specific piece of hardware. Instead, they write 
against a standardized interface (API), which simplifies the development process.

The key points of hardware abstraction include:

* **Encapsulation of Complexity**: The **Hardware Abstraction Layer (HAL)** encapsulates 
the complexity of interacting with hardware. It hides the specific details of the 
hardware, such as memory addresses, registers, and specific instructions, and provides 
a set of general functions or an API (Application Programming Interface) that is easier 
to use in application development.

* **Portability**: Hardware abstraction makes application software more portable, 
meaning it can run on different types of hardware without modification. This is 
because the abstraction layer handles the differences between hardware platforms, 
so the software doesn't have to.

* **Interoperability**: It allows different hardware components to work together 
more seamlessly, as they all adhere to a common set of standards defined by the 
abstraction layer.

* **Device Drivers**: In many systems, device drivers are a key component of hardware 
abstraction. They are specific pieces of software that know how to communicate with 
specific pieces of hardware and **translate that communication into a standard form** 
that the operating system can understand.



_Example_: TinkerCAD - [Abstraction - Different Implementations](https://www.tinkercad.com/things/fBEtVlXAG2W-arduino-7-segment-hardware-abstraction)

This example shows the use of conditional compilation (`#define`, `#ifdef` and `#endif`) 
to allow variants of an implementation.
We find this approach very often in Arduino libraries to adapt functionality to different 
Arduino boards.

*Egon Teiniker, 2020-2024, GPL v3.0*
