# Example: Hello - Serial 



## Monitor Configuration 

To display `Serial` messages in PlatformIO, we need to add the following 
settings to the `platformio.ini` file:

```ini
monitor_speed = 115200
build_flags =  
    -D ARDUINO_USB_CDC_ON_BOOT=1
```
* `monitor_speed = 115200`: This is the baud rate that PlatformIO’s 
    **Serial Monitor** uses when it opens the port. 
    It should match the rate we use in code.

* `-D ARDUINO_USB_CDC_ON_BOOT=1`: Use the ESP32-C3 native USB CDC
    serial port as `Serial` at boot.

    The XIAO ESP32C3 has **no USB-to-UART bridge chip**. Its USB-C
    connector is wired directly to the ESP32-C3's built-in USB
    Serial/JTAG controller, which is used for upload and the serial
    monitor. Without this flag, `Serial` would be routed to UART0
    (pins D6/D7) and no messages would appear in the serial monitor.


*Egon Teiniker, 2020-2026, GPL v3.0* 