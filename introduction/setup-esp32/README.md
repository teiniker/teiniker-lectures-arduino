# Setup: XIAO ESP32C3

## ArduinoIDE 

See: [Getting Started with Seeed Studio XIAO ESP32C3](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/)
	
* Board Manager **URL**: 
```
	https://espressif.github.io/arduino-esp32/package_esp32_dev_index.json
```	

* **Boards Manager** seacrh for: **esp32 by Espressif**, Version 3.3.12 

* **Board**: pick **XIAO_ESP32C3** board.
	- **Tools / USB CDC On Boot: Enabled** (this routes Serial to the USB port) - needed for the Serial Monitor.
	- Set the Serial Monitor baud to **115200**.	


## First Steps with Arduino
  * [Hello World - Serial](hello_serial/)
  * [Hello World - Blink](hello_blink/)

## References

* [Seeed Studio XIAO ESP32C3](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/)

* [ESP32 Arduino Core’s documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

*Egon Teiniker, 2020-2025, GPL v3.0* 
