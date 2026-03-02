# PlatformIO CLI

PlatformIO Core (CLI) is the command-line engine of the PlatformIO ecosystem.
It is Python-based and provides a consistent workflow for building, uploading,
testing, and monitoring embedded applications.

This README focuses on daily CLI usage in local development and automation.

## Setup

### Install PlatformIO CLI

```bash
$ pip install platformio
```

Verify installation:

```bash
$ pio --version
```

### Use the PlatformIO Terminal in VS Code

1. Open VS Code.
2. Open your PlatformIO project folder.
3. Open a new terminal (`Terminal -> New Terminal`).
4. Run `pio` commands from the project root.


## Common Commands

```bash
# Build
pio run

# Upload firmware
pio run -t upload

# Open serial monitor
pio device monitor

# Build project
pio run

# Verbose build output
pio run -v

# Clean and rebuild
pio run -t clean
pio run

# List serial devices
pio device list

# Upload firmware
pio run -t upload

# Upload using explicit serial port
pio run -t upload --upload-port /dev/ttyACM0

# Serial monitor (default settings)
pio device monitor

# Serial monitor with explicit port and baud rate
pio device monitor -p /dev/ttyACM0 -b 115200

# Run tests
pio test

# Run tests for a specific environment
pio test -e uno --upload-port /dev/ttyACM0

# Static analysis (cppcheck)
pio check

# Show firmware size report
pio run -t size
```

## Multi-Environment Usage

If your `platformio.ini` defines multiple environments, target one explicitly:

```bash
pio run -e uno
pio run -e esp32dev
pio run -e uno -t upload
```

## References

- [PlatformIO Core (CLI)](https://docs.platformio.org/en/latest/core/index.html)
- [PlatformIO CLI Command Reference](https://docs.platformio.org/en/latest/core/userguide/index.html)

_Egon Teiniker, 2020-2026, GPL v3.0_
