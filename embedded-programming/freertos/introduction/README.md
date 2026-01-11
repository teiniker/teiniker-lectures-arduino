# FreeRTOS

A **Real-Time Operating System (RTOS)** is a type of computer operating system 
designed to be small and deterministic. 

RTOSes are commonly used in embedded systems such as medical devices and 
automotive ECUs that need to react to external events within strict time 
constraints. 

## Multitasking

The kernel is the core component within an operating system. 
General purpose operating systems, such as Linux, employ kernels that allow 
multiple users to access the computer's processor seemingly simultaneously. 
These multiple users can each execute multiple programs apparently concurrently.

Each executing program is implemented by one or more threads under control of 
the operating system. If an operating system can execute multiple threads in 
this manner it is said to be multitasking. 

Small RTOSes, like FreeRTOS, normally call threads tasks because they don't 
support virtual memory, so there is no distinction between processes and threads.

The use of a multitasking operating system can simplify the design of what would 
otherwise be a complex software application:

* The **multitasking and inter-task communications features** of the operating 
    system allow the complex application to be partitioned into a set of smaller 
    and more manageable tasks.

* The **partitioning** can result in easier software testing, dividing work within 
    teams, and code reuse.

* **Complex timing and sequencing** details become the responsibility of the RTOS 
    kernel, removing that burden from the application code.


## Scheduling

The scheduler is the part of the kernel responsible for **deciding which task should 
be executing at any particular time**. The kernel can pause and later resume a task 
many times during the task's lifetime. 

**Real-time embedded systems** are designed to provide a timely response to real world 
events. Events occurring in the real world can have deadlines before which the 
real-time embedded system must respond and the RTOS scheduling policy must ensure 
these deadlines are met.

To achieve this objective using a small RTOS, we must assign a **priority** to each 
task. The **scheduling policy of the RTOS** is then to simply ensure that the highest 
priority task that is able to execute is the task given processing time. 
This may optionally include sharing processing time "fairly" between tasks of equal 
priority if there is more than one task at the same highest priority that are able 
to run (are not delaying and are not blocked).

The application writer must ensure the timing constraints are feasible to meet 
with the selected task prioritisations.

_Example_: Keypad, LCD and control algorithm

* A user must get **visual feedback of each key press** within a reasonable period.
    If the user cannot see that the key press has been accepted within this period 
    the software product will at best be awkward to use (soft real-time). 
    
    If the longest acceptable period was **100ms** (any response between 0 and 100ms 
    would be acceptable). 

* The real-time system is also performing a **control function** that relies on a digitally 
    filtered input. The input must be sampled, filtered and the control cycle executed 
    every **2ms**.

We must **assign the control task the highest priority** as:

* The deadline for the control task is stricter than that of the key handling task.

* The consequence of a missed deadline is greater for the control task than for 
    the key handler task.


## FreeRTOS and the Arduino Framework on ESP32-C6

FreeRTOS is the OS kernel that **Espressif IoT Development Framework (ESP-IDF)** 
boots and runs everything on, and the **Arduino framework is layered on top 
of that**.


On the ESP32-C6, we find the following software layers:

![ESP32 Software Stack](figures/ESP32-Stack.png)

* **Arduino Sketch**: Our application code using  `setup()` and `loop()`.

* **Arduino-ESP32 Core**: Provides Arduino APIs (`pinMode()`, `digitalWrite()`, 
    Serial, WiFi, etc.) but implemented using IDF facilities and running 
    inside IDF/FreeRTOS. 

* **ESP-IDF**: Drivers, Wi-Fi/BLE stacks, event loop, timers, NVS, etc.

* **FreeRTOS** (as an ESP-IDF component): Scheduler, tasks, queues, 
    semaphores, timers, ISR-to-task handoff, etc. 

* **ESP32-C6 Hardware +Bootloader**: RISC-V core, Interrupt controller,
     ROM startup code


Due to this software architecture, the following implications arise for 
the Arduino Framework:

* **The FreeRTOS scheduler is started by ESP-IDF, before your Arduino code**:
    In ESP-IDF, the runtime initializes hardware and FreeRTOS, then runs 
    the application entrypoint (`app_main`) inside a FreeRTOS task.

    That is why in Arduino-on-ESP32 you must not call `vTaskStartScheduler()` 
    yourself, FreeRTOS is already running when `setup()` begins.

* **setup() / loop() are executed by an Arduino-created FreeRTOS task**:
    Arduino-ESP32 creates a dedicated task (commonly referred to as loopTask) 
    and runs:
    - `setup()` once, then
    - `loop()` repeatedly

* **Arduino functions often map directly to FreeRTOS primitives**:
    A concrete example: `delay(ms)` in Arduino on ESP32 generally blocks 
    the current task rather than busy-waiting, by calling a FreeRTOS 
    delay (so other tasks keep running).

* **Our sketch coexists with many ESP-IDF system tasks**:
    Even if we only write a single-threaded Arduino sketch, the system 
    typically has other FreeRTOS tasks (networking, event loop, timers, 
    idle task, etc.). 
    
    ESP-IDF also adds supplemental facilities (like ring buffers and extra 
    hooks) that many components use.

* **Single-core scheduling still works the same way**:
    ESP32-C6 is a single-core RISC-V chip, so there’s no "pin to core 0/1" 
    in the way classic dual-core ESP32 does—but FreeRTOS still multiplexes 
    all tasks on that one core via preemption/time slicing and priorities. 


## References

* [YouTube (Digi-Key Electronics): Part 1: What is a Real-Time Operating System (RTOS)?](https://youtu.be/F321087yYy4)

* [YouTube (Digi-Key Electronics): Part 2: Getting Started with FreeRTOS](https://youtu.be/JIr7Xm_riRs)

* [YouTube (Simply Explained): What is FreeRTOS?](https://youtu.be/kP-pP6FEu8I)
    FreeRTOS can be used from within ESP IDF and Arduino.    

* [RTOS Fundamentals](https://www.freertos.org/Documentation/01-FreeRTOS-quick-start/01-Beginners-guide/01-RTOS-fundamentals)

* [FreeRTOS](https://www.freertos.org/)
* [GitHub: FreeRTOS](https://github.com/FreeRTOS)
* [Arduino core for the ESP32](https://github.com/espressif/arduino-esp32)

*Egon Teiniker, 2020-2025, GPL v3.0* 