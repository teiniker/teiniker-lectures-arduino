# Example: Hello - Serial 



## Monitor Configuration 

To display `Serial` messages in PlatformIO, we need to add the following 
settings to the `platformio.ini` file:

```ini
monitor_speed = 115200
build_flags =  
    -D ARDUINO_USB_CDC_ON_BOOT=0
```
* `monitor_speed = 115200`: This is the baud rate that PlatformIO’s 
    **Serial Monitor** uses when it opens the port. 
    It should match the rate we use in code.

* `-D ARDUINO_USB_CDC_ON_BOOT=0`: Do not use the ESP32-C6 native USB 
    CDC serial port as Serial at boot.
    We use this setting when **connected to the USB Type-C to UART Port**.

    For the ESP32-C6-DevKitC-1, this is usually what we want when using 
    the **USB-to-UART connector** for upload and serial monitor.
    `Serial` messages go through the board’s USB-to-UART bridge, 
    not the native ESP32-C6 USB port.


*Egon Teiniker, 2020-2026, GPL v3.0* 