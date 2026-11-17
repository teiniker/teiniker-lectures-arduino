# Setup Arduino IDE

The easiest way to program the Arduino board is with the **Arduino IDE**. 

This is a very simple development environment that comes with all the tools needed 
to write the source code, compile it and load it onto the Arduino board.

* Download the Arduino IDE: Go to [download](https://www.arduino.cc/en/software/)

Note that in the Virtual Lab (Debian VM) the Arduino IDE is already installed.


## Arduino Uno R3 Configuration

* **Board**:
    - ```Tools / Boards / Arduino AVR Boards / Arduino Uno```
    
    - ```Tools / Port / ```

## XIAO ESP32C3 Configuration 

* Board Manager **URL**: 
```
	https://espressif.github.io/arduino-esp32/package_esp32_dev_index.json
```	

* **Boards Manager** seacrh for: **esp32 by Espressif**, Version 3.3.12 

* **Board**: pick **XIAO_ESP32C3** board.
	- ```Tools / USB CDC On Boot: Enabled``` 
        (this routes Serial to the USB port) - needed for the Serial Monitor.
	- Set the Serial Monitor baud to **115200**.	


## References

* [Arduino IDE Download](https://www.arduino.cc/en/software/)
* [Getting Started with Arduino products](https://www.arduino.cc/en/Guide)

* [Seeed Studio XIAO ESP32C3](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/)
* [ESP32 Arduino Core’s documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

*Egon Teiniker, 2020-2026, GPL v3.0* 