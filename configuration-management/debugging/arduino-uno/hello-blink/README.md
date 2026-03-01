# Software Debugger for Arduino Uno / Nano

**avr_debug** is a debugger for Arduino based on GNU Debugger (GDB). 
The debugger is implemented using GDB stub mechanism. This means a piece 
of code (stub) is added to your Arduino program. This code then 
communicates with the GDB debugger. 

**No external programmer or modification of the Arduino board is required**.

## Blink Example

We demonstrate the usage of this software debugger on a simple blink sketch.

The implementation involves two key components:

* **platformio.ini Configuration**: Sets up the debugging environment with the avr-stub debugger tool and specifies the communication port.

* **Arduino Sketch**: Includes the `avr8-stub.h` header and calls `debug_init()` in the setup function to initialize the debugger before your application code runs.

Once configured, you can set breakpoints, step through code, and inspect variables using GDB commands through the PlatformIO debugger interface.


_Example:_ platformio.ini

```
[env:uno]
platform = atmelavr
board = uno
framework = arduino
monitor_speed = 115200

debug_tool = avr-stub
debug_port = COM5 

lib_deps = jdolinay/avr-debugger@1.5
```

_Example:_ Arduino sketch

```C++
#include <Arduino.h>
#include"avr8-stub.h"   // <==

void setup() 
{
    debug_init();       // <==
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
    digitalWrite(LED_BUILTIN, HIGH);               
    delay(1000);                             
    digitalWrite(LED_BUILTIN, LOW);        
    delay(1000);  
}
```

We can set breakpoints and start the debugger `[F5]`.

## Debugger Limitations

* One external interrupt pin must be reserved for the debugger.

* During debugging the **UART module** (e.g. Arduino Serial class) 
    **cannot be used** in our program.


## References

* [PlatformIO: avr-stub](https://docs.platformio.org/en/stable/plus/debug-tools/avr-stub.html)

* [GitHub: avr_debug](https://github.com/jdolinay/avr_debug)

*Egon Teiniker, 2020-2026, GPL v3.0* 