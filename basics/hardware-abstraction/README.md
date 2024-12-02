# Hardware Abstraction 

Hardware abstraction is a concept in computing and software engineering that 
involves **creating an abstraction layer between the software** (like an 
operating system or an application) **and the physical hardware** of a computer 
system. This abstraction layer allows software to interact with the hardware 
in a general or simplified way, rather than needing to directly manage the details 
and complexities of the hardware.


## Hardware Abstraction Layer (HAL)

The concept of a **Hardware Abstraction Layer (HAL)** is an essential component 
in both system software and embedded systems design. The HAL acts as an intermediary 
layer that provides a consistent and simplified interface to interact with hardware. 
This abstraction allows software applications and higher-level system components to 
operate independently of specific hardware details. 

Here are some key aspects of a HAL:

* **Simplification of Software Development**: By using a HAL, developers can 
    write code at a higher level of abstraction without worrying about the 
    intricacies of the hardware. 
    This makes software development faster and more efficient.

* **Portability**: Software designed with a HAL is more portable across different 
    hardware platforms. Since the hardware-specific code is confined to the HAL, 
    only this layer needs to be adapted for new hardware, while the rest of the 
    software remains unchanged.

* **Hardware Independence**: HAL enables software to run on different hardware 
    platforms without requiring modifications. It achieves this by abstracting 
    the details of the hardware, like CPU architecture or peripheral devices, 
    behind a uniform interface.

* **Consistency**: It provides a consistent programming interface across various 
    hardware platforms, which is particularly beneficial in environments where 
    multiple hardware configurations are common, such as in embedded systems, 
    consumer electronics, or computing devices.

* **Enhanced Security and Stability**: By isolating the hardware from the software, 
    a HAL can also improve system stability and security. Faults or vulnerabilities 
    at the hardware level can be contained within the HAL, reducing the risk to 
    the overall system.


## Register Programming

Without hardware abstraction, every application would have to be programmed 
down to the register level. This is not only tedious, but also reduces the 
reusability of the application for different boards.

_Example:_ [Programming I/O Ports via Registers](register-programming/io-ports/)


Have a look on the following tutorials created by **Mitch Davis** on YouTube: 
* [Intro to registers](https://youtu.be/tBq3sO1Z-7o?si=r_6gOaQlL2HEGAYl)
* [Set Registers by Memory Address](https://youtu.be/W8REqKlGzDY?si=2senXEQiFCUqhx3g)
* [Barebones Microcontroller](https://youtu.be/tfTCFBqPzcE?si=x2brcGTF_hgZyx7o)
* [Bootloaders and Programmers](https://youtu.be/dcLeKj00t_I?si=bHLBwApwMflpI-UB)
* [AVRDude and fuses](https://youtu.be/Q2DakPocvfs?si=-rtPUYle80QxcB-B)
* [Compilers, Assemblers, and Friends](https://youtu.be/7lcY5tcP_ow?si=nRIHUNCrepeqPQNd)
* [Libraries (Preprocessor & Linker)](https://youtu.be/EOuNU89TdVU?si=extE8S5eeZOadchk)
* [Optimizers and Bit-Banging](https://youtu.be/ZLyesUiXde4?si=YrW2v2VVxiouZs0Q)
* [Review; ATTiny85 from scratch](https://youtu.be/N591sLGYWnM?si=DywXeAwhOajquhfe)


## Abstraction Techniques

By abstracting the hardware, application developers don't need to write code 
for each specific piece of hardware. Instead, they write against a standardized 
interface (API), which simplifies the development process.

### Macros and Conditional Compilation

Abstract hardware-specific details and enable compiling the same codebase for 
different hardware targets.

* Use `#define` to create hardware-specific constants and inline functions.

* Utilize `#ifdef`, `#ifndef`, `#if`, `#else`, and `#endif` to include or 
    exclude code based on hardware configurations.

_Example_: Define platform specific constants (`variants/standard/pins_arduino.h`)

```C++
#define LED_BUILTIN 13

#define PIN_A0   (14)
#define PIN_A1   (15)
#define PIN_A2   (16)
#define PIN_A3   (17)
#define PIN_A4   (18)
#define PIN_A5   (19)
#define PIN_A6   (20)
#define PIN_A7   (21)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
```

* `LED_BUILTIN` is a macro that represents the pin number connected to the 
    built-in LED on the Arduino board.

* `PIN_A0`, `PIN_A1`, etc., are macros that represent the analog input pins 
    on the Arduino board.

* `A0`, `A1`, etc., are constants that are defined as aliases for the analog 
    input pins.

By using such mappings and constants, Arduino sketches can remain consistent 
and easier to understand, especially when transitioning between different 
Arduino boards or when modifying hardware configurations.

**#define vs. const**:

* **#define**
    * A preprocessor directive that replaces occurrences of the macro with 
    its value before compilation.
    * Does not have a type, which can sometimes lead to unexpected behaviors.

* **const**
    * Defines typed constants that the compiler can understand, enabling type 
    checking and better debugging.
    * Respects scope and can ble scoped to namespaces or classes in C++.        


_Example_: [TinkerCAD - Conditional compilation](https://www.tinkercad.com/things/fBEtVlXAG2W-arduino-7-segment-hardware-abstraction)

    This example shows the use of conditional compilation (`#define`, `#ifdef` and `#endif`) 
    to allow variants of an implementation. We find this approach very often in Arduino 
    libraries to adapt functionality to different Arduino boards.


_Example_: Conditional compilation for hardware-specific features (`cores/arduino/HardwareSerial.h`)

```C++
#if defined(UBRRH) || defined(UBRR0H)
  extern HardwareSerial Serial;
  #define HAVE_HWSERIAL0
#endif
#if defined(UBRR1H)
  extern HardwareSerial Serial1;
  #define HAVE_HWSERIAL1
#endif
#if defined(UBRR2H)
  extern HardwareSerial Serial2;
  #define HAVE_HWSERIAL2
#endif
#if defined(UBRR3H)
  extern HardwareSerial Serial3;
  #define HAVE_HWSERIAL3
#endif
```

The provided code snippet is responsible for conditionally declaring and enabling 
support for multiple hardware serial ports (`Serial`, `Serial1`, `Serial2`, `Serial3`) 
based on the specific AVR microcontroller being used. 

* **Registers (UBRRxH)**: UART communication is managed through specific hardware 
    registers in AVR microcontrollers. The `UBRRxH` (UART Baud Rate Register High byte) 
    is part of the register set that configures the baud rate for UART communication. 
    Different UART interfaces on a microcontroller are typically denoted by numbers 
    (e.g., UBRR0H, UBRR1H, etc.), corresponding to different UART hardware modules.

* **HardwareSerial**: In the Arduino framework, `HardwareSerial` is a class that provides 
    methods to control the UART hardware for serial communication. 
    Instances of this class (`Serial`, `Serial1`, etc.) represent different UART interfaces 
    available on the microcontroller.

* **Conditional Compilation**: The `#if defined(...)` directives check whether specific 
    macros (e.g., `UBRRH`, `UBRR0H`, `UBRR1H`, etc.) are defined. These macros are typically 
    defined in the microcontroller's header files and indicate the presence of specific 
    UART hardware modules.

AVR-based Arduino boards come with varying numbers of hardware UARTs:

* **Arduino Uno**, **Nano**, **Mini**: Typically have one hardware UART (`Serial`).

* **Arduino Mega 2560**: Has four hardware UARTs (`Serial`, `Serial1`, `Serial2`, `Serial3`).

* **Arduino Leonardo**, **Micro**: Have one or more UARTs with different configurations.


### Header Files for Interface Separation

Separate the hardware abstraction interface from its implementation, promoting 
modularity and easier maintenance.

* Declare interfaces in header files `.h`, and implement them in source files `.c`.

* Allow different implementations to be swapped without altering application code.

_Example_: I2C library header file (`Wire.h`)
```C++
#ifndef TwoWire_h
#define TwoWire_h

class TwoWire : public Stream
{
    //...
};

extern TwoWire Wire;

#endif    
```

_Example_: I2C library implementation file (`Wire.cpp`)
```C++
#include "Wire.h"

void TwoWire::begin(void)
{
  rxBufferIndex = 0;
  rxBufferLength = 0;

  txBufferIndex = 0;
  txBufferLength = 0;

  twi_init();
  twi_attachSlaveTxEvent(onRequestService); // default callback must exist
  twi_attachSlaveRxEvent(onReceiveService); // default callback must exist
}
//...
```

Creating an **alternative implementation** for the `Wire.h` header involves 
providing a new version of the `Wire.cpp` (and potentially `Wire.h`) files 
that conform to the expected interface but offer different functionalities, 
optimizations, or support for different hardware configurations.

Each implementation file is compiled into an **object file**, e.g. `Wire.cpp` 
becomes `Wire.o`. These object files are linked by the **linker** to the final 
executable.
By using different implementations (e.g. `Wire.cpp`), different object files 
can be created and linked during the build process.

_Example_: [Port Extension (74HC595)](hardware-abstraction/port-extension/README.md)


### Modularization and Separation of Concerns

Organize code into **distinct modules** based on functionality, each handling 
specific aspects of hardware abstraction.

* Create separate modules for different hardware components (e.g., UART, SPI, I2C).

* Ensure that higher-level application code interacts only with the abstraction 
    layer, not the hardware directly.

* By implementing the abstractions for hardware components in separate modules
    (e.g. `Wire.h` and `Wire.cpp`), it is easy to link only the object files 
    needed for a specific application in the build process.

_Example_: [Build an Arduino Library](arduino-library/)


### Object-Oriented Programming (OOP)

OOP offers a set of principles and paradigms that can significantly enhance hardware 
abstraction in embedded systems. Adopting OOP concepts—typically through languages 
like C++ can lead to more modular, maintainable, and scalable codebases. 

_Example_: [Port Extension (74HC595)](hardware-abstraction/port-extension/README.md)


### Frameworks

Leverage existing libraries and frameworks that provide high-level abstractions
for common hardware components and functionalities.

* Use libraries like Arduino, mbed, or CMSIS to simplify hardware interaction.

* Develop custom libraries for specific hardware components or functionalities.



*Egon Teiniker, 2020-2024, GPL v3.0*
