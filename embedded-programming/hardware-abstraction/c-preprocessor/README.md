# Abstraction Techniques Using in C Preprocessor

By abstracting the hardware, application developers don't need to write code 
for each specific piece of hardware. Instead, they write against a standardized 
interface (API), which simplifies the development process.

The following abstraction techniques refer to mechanisms in C/C++ that can be 
performed by the **C Preprocessor**.
This has the advantage that the generated binary has only a minimal size.

## Macros 

Abstract hardware-specific details and enable compiling the same codebase for 
different hardware targets.

* Use `#define` to create hardware-specific constants and inline functions.

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


## Conditional Compilation

If we want to use the same functionality on different microcontrollers, we 
often have to exchange parts of the code within a function. This can be 
achieved using pre-processor instructions for conditional compilation.

* Utilize `#ifdef`, `#ifndef`, `#if`, `#else`, and `#endif` to include or 
    exclude code based on hardware configurations.

_Example_: [TinkerCAD - 7 Segment Output](https://www.tinkercad.com/things/fBEtVlXAG2W-arduino-7-segment-hardware-abstraction)

This example shows the use of conditional compilation (`#define`, `#ifdef` and `#endif`) 
to allow variants of an implementation. We find this approach very often in Arduino 
libraries to adapt functionality to different Arduino boards.


_Example_: AVR Arduino Core - [HardwareSerial.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/HardwareSerial.h)

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


## References

* K. N. King. **C Programming, A Modern Approach.** W. W. Norton & Company, inc. 2nd Edition 2008. 
    * Chapter 14: The Preprocessor
    
* Norman Dunbar. **Arduino Software Internals**. APress 2020
    * Chapter 3: Arduino Language Reference

*Egon Teiniker, 2020-2025, GPL v3.0*
