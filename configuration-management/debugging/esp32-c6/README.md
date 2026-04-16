# ESP32 Debugging using ESP-Prog

To be able to debug programs on the ESP32, we need an ESP-Prog 
to control the ESP32's JTAG interface.

**JTAG (Joint Test Action Group)**: This is the industry-standard 
hardware interface used for verifying designs and debugging chips.

Unlike a serial (UART) connection that just sends text, 
**JTAG connects directly to the internal logic of the processor**. 

It allows a debugger to:

* Pause the CPU at any moment (halt).

* Step through code line by line.

* Inspect and modify registers and memory in real-time.

* Set breakpoints, which stop the program when a specific memory address is reached.

To use JTAG, we need a **bridge between our computer and the chip**: 

* Your Computer (GDB/IDE): Sends a command like "Stop at line 42."

* OpenOCD: Software on your PC that translates high-level commands 
    into JTAG bit-sequences.

* ESP-Prog: Converts USB signals into the physical 
    electrical pulses for the TMS/TCK/TDI/TDO pins.

* ESP32: Receives the signals and halts the CPU.


**ESP-Prog**: This is the specific hardware bridge provided by Espressif. 
It acts as a translator between your computer (via USB) and the ESP32’s 
JTAG pins.

![ESP-Prog](figures/esp-prog.jpg)

![Connector](figures/ESP32-Prog-Connection.png)


Unfortunately, **PlatformIO does not yet support debugging for the ESP32-C6 
using the Arduino framework**.
The ESP32-C6 is a relatively new chip (based on the RISC-V architecture), 
and the ecosystem support often lags behind the hardware release.

## References

* [ESP-Prog](https://docs.platformio.org/en/latest/plus/debug-tools/esp-prog.html)

*Egon Teiniker, 2020-2026, GPL v3.0* 