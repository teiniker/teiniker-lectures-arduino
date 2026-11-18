# Embedded Systems Programming 

An **embedded system** is a computer that is built into a larger device to
perform a dedicated function. Examples are washing machines, car engine
control units, pacemakers, routers or industrial controllers. In contrast
to a desktop computer, the user usually does not see the computer at all;
it only sees the behavior of the device.

**Embedded programming** is the development of software for such systems.
The software interacts directly with hardware: it reads sensors, drives
actuators and communicates with other devices via buses like UART, I2C or
SPI.

### Constraints

Embedded software runs under constraints that are rarely relevant on a
desktop or server:

* **Limited resources**: Memory is measured in kilobytes, not gigabytes.
  An Arduino Uno has 2 KB of SRAM and 32 KB of flash memory. There is no
  swap space and often no dynamic memory allocation.

* **Limited processing power**: Clock rates range from a few MHz to a few
  hundred MHz. Many microcontrollers have no floating point unit, so
  floating point operations are emulated in software.

* **Power consumption**: Battery powered devices must run for months or
  years. The software has to use sleep modes and switch off unused
  peripherals.

* **Cost**: Devices are produced in large quantities. A few cents saved on
  a cheaper microcontroller add up, so the software must fit into the
  smallest possible chip.

* **Timing**: Many systems must react to external events within a fixed
  time. A late reaction can be as wrong as a wrong result.

* **Reliability and safety**: Embedded systems often run for years without
  a restart and without a user who could fix a problem. Failures can
  damage hardware or endanger people.

### Challenges

These constraints lead to typical challenges in embedded software
development:

* **Cross-development**: The code is written and compiled on a host
  computer (e.g. x86 Linux) for a different target architecture (e.g.
  AVR or RISC-V) and then uploaded to the device.

* **Hardware dependency**: The software accesses registers of the
  microcontroller and depends on the wiring of the board. Datasheets
  become an essential part of the documentation.

* **Concurrency**: Interrupts, timers and multiple tasks run concurrently
  and access shared data. This causes race conditions that are hard to
  reproduce.

* **Debugging and testing**: There is often no screen and no debugger
  attached. Developers rely on serial output, LEDs, logic analyzers or
  hardware debuggers. Unit tests run either on the host or on the target
  device.

Depending on the complexity of the application, embedded systems are
built on three kinds of software platforms, which are described below.


## Bare-Metal Systems 

In a **bare-metal system** the application runs directly on the hardware
without an operating system. The program is the only software on the
chip (apart from an optional bootloader). It is responsible for
everything: initializing the clock, configuring peripherals, handling
interrupts and managing memory.

The typical program structure is a **super loop**: after an
initialization phase, the program runs an endless loop that polls inputs,
computes outputs and writes them to the hardware. Time-critical events
are handled by **interrupt service routines (ISRs)** that interrupt the
super loop.

```C
int main(void)
{
    init();             // hardware initialization

    for(;;)             // super loop
    {
        read_inputs();
        process();
        write_outputs();
    }
}
```

Advantages:
* Small memory footprint and fast startup.
* Full control over the hardware and predictable timing.
* Simple toolchain and simple program structure.

Disadvantages:
* No separation of concerns: a slow function delays everything else in
  the loop.
* Concurrency must be implemented manually (state machines, timers,
  interrupts).
* Code is tightly coupled to the hardware and hard to port.

### Example: Arduino Uno R3

The **Arduino Uno R3** is a classic example of a bare-metal platform.
It is based on the **ATmega328P**, an 8-bit AVR microcontroller.

| Property         | Value                                  |
|:--               |:--                                     |
| CPU              | ATmega328P, 8-bit AVR, 16 MHz          |
| Flash memory     | 32 KB (0.5 KB used by the bootloader)  |
| SRAM             | 2 KB                                   |
| EEPROM           | 1 KB                                   |
| Digital I/O pins | 14 (6 of them with PWM)                |
| Analog inputs    | 6 (10-bit ADC)                         |
| Operating voltage| 5 V                                    |
| Peripherals      | UART, I2C, SPI, 3 timers               |

The Arduino framework hides the super loop behind the functions
`setup()` and `loop()`. The framework's own `main()` function calls
`init()` to configure timers and the ADC, then calls `setup()` once and
`loop()` repeatedly:

```C
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}
```

Note that `delay()` blocks the CPU: during the 500 ms nothing else can be
done in the loop. Avoiding such blocking calls with timers, interrupts
and state machines is a central topic of bare-metal programming.


## Realtime Systems

A **realtime system** is a system whose correctness depends not only on
the logical result of a computation but also on the **time** at which the
result is produced. Realtime does not mean "fast", it means
**predictable**: every reaction must happen within a known deadline.

* **Hard realtime**: Missing a deadline is a system failure (e.g. airbag
  control, motor control, braking systems).

* **Soft realtime**: Missing a deadline degrades the quality but is not
  fatal (e.g. audio or video streaming, user interfaces).

When an application consists of several independent activities with
different timing requirements, a super loop becomes hard to maintain. A
**realtime operating system (RTOS)** solves this problem by splitting
the application into **tasks** (threads). The RTOS provides:

* A **preemptive, priority-based scheduler**: The task with the highest
  priority that is ready to run always gets the CPU. A high priority task
  interrupts a lower priority task immediately.

* **Deterministic timing**: Kernel operations have bounded execution
  times, and a periodic tick interrupt (e.g. every 1 ms) is used for
  delays and timeouts.

* **Inter-task communication and synchronization**: Queues, semaphores,
  mutexes and event groups.

An RTOS is a small library linked together with the application into a
single firmware image. There is no separation between kernel and user
space and usually no memory protection.

### Example: XIAO ESP32C3 with FreeRTOS

The **Seeed Studio XIAO ESP32C3** is a tiny board based on Espressif's
**ESP32-C3**, a 32-bit RISC-V microcontroller with integrated WiFi and
Bluetooth.

| Property         | Value                                  |
|:--               |:--                                     |
| CPU              | ESP32-C3, 32-bit RISC-V, up to 160 MHz |
| Flash memory     | 4 MB                                   |
| SRAM             | 400 KB                                 |
| Digital I/O pins | 11 (all with PWM)                      |
| Analog inputs    | 4 (12-bit ADC)                         |
| Operating voltage| 3.3 V                                  |
| Wireless         | WiFi 802.11 b/g/n, Bluetooth 5 (LE)    |
| Peripherals      | UART, I2C, SPI, timers, USB Serial/JTAG|

The ESP32 software stack (ESP-IDF) is built on **FreeRTOS**, a widely
used open source RTOS. Even a plain Arduino sketch runs inside FreeRTOS:
`setup()` and `loop()` are executed in a task called `loopTask`, while
the WiFi and Bluetooth stacks run in their own tasks.

Applications can create additional tasks directly with the FreeRTOS API:

```C
void blink_task(void *parameter)
{
    pinMode(LED_PIN, OUTPUT);
    for(;;)
    {
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
        vTaskDelay(pdMS_TO_TICKS(500));     // block, let other tasks run
    }
}

void setup()
{
    xTaskCreate(blink_task, "blink", 2048, NULL, 1, NULL);
}

void loop()
{
    // other work, independent of the blinking LED
}
```

In contrast to `delay()` on a bare-metal system, `vTaskDelay()` does not
waste CPU time: the task is blocked and the scheduler switches to another
ready task.

See [FreeRTOS](../freertos/) for details.


## Embedded Linux Systems

An **embedded Linux system** runs a full Linux operating system on an
application processor. Such processors have a **memory management unit
(MMU)**, which enables virtual memory, process isolation and the
separation of kernel space and user space.

Typical properties:

* The hardware is accessed through **device drivers** in the kernel.
  Applications use files and system calls (e.g. `/dev/gpiochip0`,
  `/dev/i2c-1`, `/dev/ttyAMA0`) instead of writing registers directly.

* The full Linux ecosystem is available: multiple processes, file
  systems, networking (TCP/IP, SSH, HTTP), and programming languages like
  C, C++, Python, Java or Rust.

* The system boots from an SD card or embedded MultiMediaCard (eMMC) and 
  needs RAM in the range of hundreds of megabytes. 
  Booting takes seconds instead of milliseconds.

* Standard Linux is **not a hard realtime system**. Interrupt latencies
  are larger and less predictable than on a microcontroller. The
  `PREEMPT_RT` patch set (part of the mainline kernel since version 6.12)
  improves determinism, but time-critical I/O is often still delegated to
  a separate microcontroller.

Embedded Linux is used when an application needs complex software:
graphical user interfaces, networking, databases, cameras or machine
learning.

### Example: Raspberry Pi 5

The **Raspberry Pi 5** is a single board computer that is widely used for
embedded Linux applications.

| Property         | Value                                       |
|:--               |:--                                          |
| CPU              | Broadcom BCM2712, 4x ARM Cortex-A76, 64-bit, 2.4 GHz |
| RAM              | 2, 4, 8 or 16 GB LPDDR4X                    |
| Storage          | microSD card, optional NVMe SSD via PCIe    |
| I/O controller   | RP1 (GPIO, UART, I2C, SPI, USB, Ethernet)   |
| GPIO             | 40-pin header, 3.3 V                        |
| Connectivity     | Gigabit Ethernet, WiFi, Bluetooth 5.0, USB 3.0 |
| Operating system | Raspberry Pi OS (Debian based)              |

On the Raspberry Pi 5 the GPIO pins are connected to the RP1 I/O
controller and are accessed via the Linux GPIO character device using
the **libgpiod** library:

```C
#include <gpiod.h>
#include <unistd.h>

int main(void)
{
    struct gpiod_chip *chip = gpiod_chip_open("/dev/gpiochip0");
    struct gpiod_line_settings *settings = gpiod_line_settings_new();
    gpiod_line_settings_set_direction(settings, GPIOD_LINE_DIRECTION_OUTPUT);

    struct gpiod_line_config *config = gpiod_line_config_new();
    unsigned int offset = 17;   // GPIO17
    gpiod_line_config_add_line_settings(config, &offset, 1, settings);

    struct gpiod_line_request *request =
        gpiod_chip_request_lines(chip, NULL, config);

    for(int i = 0; i < 10; i++)
    {
        gpiod_line_request_set_value(request, offset,
                                     GPIOD_LINE_VALUE_ACTIVE);
        usleep(500000);
        gpiod_line_request_set_value(request, offset,
                                     GPIOD_LINE_VALUE_INACTIVE);
        usleep(500000);
    }

    gpiod_line_request_release(request);
    gpiod_line_config_free(config);
    gpiod_line_settings_free(settings);
    gpiod_chip_close(chip);
    return 0;
}
```

The program is an ordinary Linux process. The kernel may suspend it at
any time to run other processes, so the blink period is only
approximately 500 ms.


## Comparison

| Property     | Bare-Metal      | RTOS             | Embedded Linux     |
|:--           |:--              |:--               |:--                 |
| Example      | Arduino Uno R3  | XIAO ESP32C3     | Raspberry Pi 5     |
| CPU          | 8-bit, 16 MHz   | 32-bit, 160 MHz  | 64-bit, 4x 2.4 GHz |
| Memory       | 2 KB SRAM       | 400 KB SRAM      | 2 to 16 GB RAM     |
| OS           | none            | FreeRTOS         | Linux              |
| Concurrency  | interrupts      | tasks            | processes, threads |
| Mem. protect.| no              | no               | yes (MMU)          |
| HW access    | registers       | registers        | kernel drivers     |
| Timing       | very predictable| predictable      | best effort        |
| Startup time | milliseconds    | milliseconds     | seconds            |
| Power usage  | very low        | low              | high               |


*Egon Teiniker, 2020-2026, GPL v3.0* 
