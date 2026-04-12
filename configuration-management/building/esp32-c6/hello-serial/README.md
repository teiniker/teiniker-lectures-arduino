# Example: Hello - Serial 



## Monitor Configuration 

To display `Serial` messages in PlatformIO, we need to add the following 
settings to the `platformio.ini` file:

```ini
monitor_speed = 115200
build_flags =  
    -D ARDUINO_USB_CDC_ON_BOOT=1
    -D ARDUINO_USB_MODE=1
```
* `monitor_speed = 115200`: This is the baud rate that PlatformIO’s 
    **Serial Monitor** uses when it opens the port. 
    It should match the rate we use in code.

* `-D ARDUINO_USB_CDC_ON_BOOT=1`: This tells Arduino-ESP32 to 
    **enable the USB CDC serial interface at boot**. 
    
    In practice, that means the board exposes a USB serial device 
    immediately after startup, so our `Serial` output can go to 
    the USB connection without needing an external USB-to-UART chip. 
    
    Espressif’s docs describe USB CDC as the interface used for 
    serial communication over the chip’s built-in USB, and they list 
    ESP32-C6 as a supported CDC device.

* `-D ARDUINO_USB_MODE=1`: This selects which USB serial backend 
    Arduino maps Serial to. In the Arduino-ESP32 core, the mapping 
    is controlled in `HardwareSerial.h`: one mode maps `Serial` to 
    `USBSerial`, and the other maps it to `HWCDCSerial`.

    For ESP32-C6, `=1` is the important choice because the chip 
    supports the hardware USB Serial/JTAG CDC path, and Arduino’s 
    HWCDC example explicitly lists ESP32-C6 as supported. 

*Egon Teiniker, 2020-2026, GPL v3.0* 