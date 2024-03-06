# FreeRTOS 

FreeRTOS is a **real-time operating system (RTOS)** for microcontrollers 
and small microprocessors. Distributed freely under the MIT open source license.

FreeRTOS includes a kernel and a growing set of IoT libraries suitable for use 
across all industry sectors.


## Arduino FreeRTOS Library

This is a fork of Richard Barry's freeRTOS, **optimised for the Arduino AVR devices**
If you want to use FreeRTOS on the Renesas family of Arduino like the **Arduino UNO R4, 
it is already included**.

The **AVR Watchdog Timer** is used with to generate 15ms time slices, but Tasks that finish 
before their allocated time will hand execution back to the Scheduler. 
This does not affect the use of any of the normal Timer functions in Arduino.

**Never use the Arduino delay() function in your Tasks**, as it burns CPU cycles and doesn’t 
place the Task into Blocked State, allowing the Scheduler to place other lower priority 
tasks into Running State. 
Use **vTaskDelay()** or **vTaskDelayUntil()** instead. 

Also **never delay or Block the Arduino loop()** as this is being run by the FreeRTOS Idle 
Task, which must never be blocked.


* [Tasks](tasks/)
* [Mutex](mutex/)
* [Queues](queues/)
* Semaphore

## References

* [What is FreeRTOS?](https://youtu.be/kP-pP6FEu8I)
    FreeRTOS can be used from within ESP IDF and Arduino.    

* [Arduino_FreeRTOS_Library](https://github.com/feilipu/Arduino_FreeRTOS_Library)
* [Arduino FreeRTOS](https://feilipu.me/2015/11/24/arduino_freertos/)
* [FreeRTOS Kernel Quick Start Guide](https://www.freertos.org/FreeRTOS-quick-start-guide.html)

*Egon Teiniker, 2020-2024, GPL v3.0* 
