# Setup: ESP32-C6

## ArduinoIDE 

See: [Arduino Setup](https://docs.sparkfun.com/SparkFun_Thing_Plus_ESP32_C6/software_setup/)
	
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

* [ESP32-C6-DevKitC-1 v1.2](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32c6/esp32-c6-devkitc-1/user_guide.html)

* [ESP32 Arduino Core’s documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

*Egon Teiniker, 2020-2025, GPL v3.0* 
