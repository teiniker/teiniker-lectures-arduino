# Example: Hello - Blink


## Build Environment Configurations

To use the XIAO ESP32C3 with the Arduino Framework, we need the following
configuration:

```ini
[env:seeed_xiao_esp32c3]
platform = https://github.com/pioarduino/platform-espressif32/releases/download/stable/platform-espressif32.zip
board = seeed_xiao_esp32c3
framework = arduino
```

* [env:seeed_xiao_esp32c3]: 
    This starts one **environment** in `platformio.ini`. An environment 
    is a named build/upload configuration. 
    PlatformIO uses the name after `env:` as the environment identifier, 
    so here your environment is named `seeed_xiao_esp32c3`. 
    
    We can have multiple environments in one project, for example one 
    for release and one for testing.

* `platform = https://github.com/pioarduino/platform-espressif32/releases/download/stable/platform-espressif32.zip`: 
    This tells PlatformIO which **development platform** package to use.
    We are pointing to a specific ZIP package hosted on GitHub. That means 
    PlatformIO will use that custom platform package for toolchains, upload 
    tools, board definitions, and framework integration.

* `board = seeed_xiao_esp32c3`:
    This selects the **board definition**. PlatformIO uses this board ID 
    to load the correct board manifest and defaults such as MCU type, clock 
    frequency, flash size, and upload/debug defaults. 
    PlatformIO’s board page for `seeed_xiao_esp32c3` identifies it as the 
    Seeed Studio XIAO ESP32C3 and lists defaults including ESP32-C3, 
    160 MHz, 4 MB flash, and 320 KB RAM.

* `framework = arduino`:
    This chooses the **software framework** used to build your code. With 
    `arduino`, PlatformIO builds our project against the Arduino core for 
    ESP32, so sketches using `setup()`, `loop()`, `Serial`, `pinMode()`, 
    and `digitalWrite()` compile as Arduino code rather than as pure 
    ESP-IDF code.

Note that the XIAO ESP32C3 has **no user-controllable LED** (the onboard
LED only shows the charging state), so `LED_BUILTIN` is not defined.
We connect an external LED (with a series resistor) to pin `D2`:

```C++
const int LED_PIN = D2;
```

*Egon Teiniker, 2020-2026, GPL v3.0* 