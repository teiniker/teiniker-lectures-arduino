# Example: Hello - Blink


## Build Environment Configurations

To use the ESP32-C6 with the Arduino Framework, we need the following configuration:

```ini
[env:esp32-c6-devkitc-1]
platform = https://github.com/pioarduino/platform-espressif32/releases/download/stable/platform-espressif32.zip
board = esp32-c6-devkitc-1
framework = arduino
```

* [env:esp32-c6-devkitc-1]: 
    This starts one **environment** in `platformio.ini`. An environment 
    is a named build/upload configuration. 
    PlatformIO uses the name after `env:` as the environment identifier, 
    so here your environment is named `esp32-c6-devkitc-1`. 
    
    We can have multiple environments in one project, for example one 
    for release and one for testing.

* `platform = https://github.com/pioarduino/platform-espressif32/releases/download/stable/platform-espressif32.zip`: 
    This tells PlatformIO which **development platform** package to use.
    We are pointing to a specific ZIP package hosted on GitHub. That means 
    PlatformIO will use that custom platform package for toolchains, upload 
    tools, board definitions, and framework integration.

* `board = esp32-c6-devkitc-1`:
    This selects the **board definition**. PlatformIO uses this board ID 
    to load the correct board manifest and defaults such as MCU type, clock 
    frequency, flash size, and upload/debug defaults. 
    PlatformIO’s board page for `esp32-c6-devkitc-1` identifies it as the 
    Espressif ESP32-C6-DevKitC-1 and lists defaults including ESP32-C6, 
    160 MHz, 8 MB flash, and 320 KB RAM.

* `framework = arduino`:
    This chooses the **software framework** used to build your code. With 
    `arduino`, PlatformIO builds our project against the Arduino core for 
    ESP32, so sketches using `setup()`, `loop()`, `Serial`, `pinMode()`, 
    and `digitalWrite()` compile as Arduino code rather than as pure 
    ESP-IDF code.

*Egon Teiniker, 2020-2026, GPL v3.0* 