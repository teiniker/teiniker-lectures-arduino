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

The XIAO ESP32C3 has no USB-serial chip; its native USB Serial/JTAG
port appears as `/dev/ttyACM0`.

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

This is a teaching repository covering embedded programming with Arduino Uno (ATmega328P, 8-bit AVR) and XIAO ESP32C3 (ESP32-C3, RISC-V 32-bit). Topics are organized into top-level sections:

- `introduction/` — board setup, first sketches for Uno and ESP32
- `computer-architectures/` — combinatorial/sequential logic, microcontroller datasheets
- `embedded-programming/` — peripherals (UART, I2C, timers, interrupts), hardware abstraction, FreeRTOS, state machines, OOP
- `configuration-management/` — PlatformIO build system, library management, debugging (avr-stub, ArduinoLog), unit testing, static analysis
- `sensors-and-actuators/` — sensors (DHT11, HC-SR04), motors (servo, DC, stepper), UI components (LCD, joystick, buttons)
- `projects/` — complete standalone projects (e.g. NeoPixel)


## Documentation

* Use only 80 chars per line for documentation text.
* Don't use —, ---, and emojis in generated text.


## Figures

Diagrams in README files are PNG images generated with Python and
matplotlib, not ASCII art in code blocks. Only the PNGs are committed;
the generator script stays outside the repository.

Workflow:

* matplotlib is not installed system-wide. Create a venv in the
  scratchpad directory: `python3 -m venv venv` and
  `venv/bin/pip install matplotlib`.
* Write one script that generates all figures of a README and takes the
  output directory as argument, e.g.
  `venv/bin/python -I make_figures.py <example>/figures`.
* Store images in `<example>/figures/` with lowercase snake_case names
  prefixed by topic (e.g. `cpu_datapath.png`, `riscv_add_decoding.png`).
* Reference them in the README with `![](figures/<name>.png)`.
* After rendering, view every PNG with the Read tool and check for
  overlapping labels, misaligned arrows and empty margins. Adjust the
  axis limits and re-render until clean.
* Verify technical content in figures with real tools where possible,
  e.g. instruction encodings with `riscv32-esp-elf-as` and
  `riscv32-esp-elf-objdump` from `~/.platformio/packages/`.

Style (consistent across all figures):

* `fig, ax = plt.subplots(figsize=(w, h))`, `ax.set_aspect("equal")`,
  `ax.axis("off")`, drawing in data coordinates with `Rectangle`,
  `Polygon` and `ax.annotate` arrows (`arrowstyle="-|>"`).
* Save with `dpi=150`, `bbox_inches="tight"`, `pad_inches=0.25`,
  `facecolor="white"`.
* Default font (DejaVu Sans); title fontsize 15, labels 10 to 13,
  monospace for assembly and hex values.
* Edges `#222222`, line width 2.0, notes in grey `#555555`.
* Pastel fill palette:

| Color  | Hex       | Typical use                          |
|:--     |:--        |:--                                   |
| grey   | `#e0e0e0` | opcode, control fields, neutral      |
| orange | `#f6dccb` | registers, destination fields        |
| yellow | `#fbeac0` | multiplexers, decode stage           |
| green  | `#d5ebd2` | ALU, immediates, constants           |
| blue   | `#cfe0f1` | source registers, shifter, fetch     |
| purple | `#e2d6ee` | status bits, flags                   |
| red    | `#c0392b` | highlighted lines (e.g. buses)       |

* Use the same color for the same concept in all figures of a README
  and add a small legend when the colors carry meaning.
* Text inside figures follows the documentation rules (no dashes or
  emojis as separators).
