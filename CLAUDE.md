# CLAUDE.md

## PlatformIO CLI

PlatformIO Core 6.1.19 is installed at `~/.local/bin/pio`.

Every example in this repository is a self-contained PlatformIO project. 
All `pio` commands must be run from the project directory that contains `platformio.ini`.

```bash
# Build
pio run

# Upload firmware
pio run -t upload

# Upload with explicit port
pio run -t upload --upload-port /dev/ttyACM0

# Open serial monitor
pio device monitor

# Serial monitor with explicit port and baud rate
pio device monitor -p /dev/ttyACM0 -b 115200

# Run on-device unit tests
pio test -e uno --upload-port /dev/ttyACM0

# List connected serial devices
pio device list

# Clean build artifacts
pio run -t clean

# Generate IntelliSense compilation database
pio run --target compiledb
```

## Finding the Arduino Board via USB

On Linux, Arduino Uno (and other official Arduino boards using the ACM/CDC USB driver) appears as:

```
/dev/ttyACM0
```

To verify the connected device:
```bash
ls /dev/ttyACM* /dev/ttyUSB*
```

ESP32-C6 boards typically appear on `/dev/ttyUSB0` or `/dev/ttyACM0` depending on the USB-serial chip used.

## Project Structure

Each example follows the standard PlatformIO layout:

```
<example>/
├── platformio.ini      # board, platform, framework, lib_deps, build_flags
├── src/
│   └── main.cpp        # Arduino sketch (setup() + loop())
├── test/               # Unity unit tests (only in testing examples)
│   └── test_*.cpp
├── lib/                # local libraries (if any)
└── include/            # local headers (if any)
```


## VS Code IntelliSense

The preferred setup is plain VS Code with the clangd extension and pio
on the command line. The PlatformIO VS Code extension is not used.

Required VS Code extension: clangd (by LLVM, id:
llvm-vs-code-extensions.vscode-clangd).

The MS C/C++ IntelliSense engine is disabled in `.vscode/settings.json`
to avoid conflicts with clangd.

To enable IntelliSense for a project, generate its compilation database
once from the project directory:

```bash
pio run --target compiledb
```

This creates `compile_commands.json` next to `platformio.ini`. clangd
finds it automatically when editing any file in that project -- no
path configuration needed. Re-run after adding libraries or changing
the board.

`compile_commands.json` files are excluded via `.gitignore` because
they contain absolute paths.

## Repository Layout

This is a teaching repository covering embedded programming with Arduino Uno (ATmega328P, 8-bit AVR) and ESP32-C6 (RISC-V 32-bit). Topics are organized into top-level sections:

- `introduction/` — board setup, first sketches for Uno and ESP32
- `computer-architectures/` — combinatorial/sequential logic, microcontroller datasheets
- `embedded-programming/` — peripherals (UART, I2C, timers, interrupts), hardware abstraction, FreeRTOS, state machines, OOP
- `configuration-management/` — PlatformIO build system, library management, debugging (avr-stub, ArduinoLog), unit testing, static analysis
- `sensors-and-actuators/` — sensors (DHT11, HC-SR04), motors (servo, DC, stepper), UI components (LCD, joystick, buttons)
- `projects/` — complete standalone projects (e.g. NeoPixel)


## Documentation

* Use only 80 chars per line for documentation text.
* Don't use —, ---, and emojis in generated text.

