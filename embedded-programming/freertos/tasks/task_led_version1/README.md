# Example: Blinking LEDs Using vTaskDelay()

This example creates two tasks running concurrent using FreeRTOS.

## delay() vs vTaskDelay()

When we are programming FreeRTOS on an ESP32-C6, the difference between 
`delay()` and `vTaskDelay()` inside a task is very important. 

> Inside a FreeRTOS task, you should use `vTaskDelay()`, not `delay()`.

### delay()

* Comes from the Arduino framework
* **Measured in milliseconds**
* Designed **for single-threaded loop()** code

On ESP32, `delay()` is implemented as a wrapper around FreeRTOS but only 
safely for `loop()`, not for arbitrary tasks.

Internally, it:
* Blocks the calling context
* Is tied to the Arduino main task (loopTask)
* May interfere with task scheduling when used elsewhere

Therefore, **delay() is not recommended inside FreeRTOS tasks**.


### vTaskDelay()

* A native FreeRTOS API
* **Measured in ticks**, not milliseconds
* Designed specifically **for tasks**

Using vTaskDelay() it:
* Suspends only the calling task
* Frees the CPU so other tasks can run
* Integrates cleanly with:
    - Task priorities
    - Scheduler
    - Watchdogs


### pdMS_TO_TICKS()

`pdMS_TO_TICKS()` is a FreeRTOS macro that converts milliseconds into RTOS 
ticks, which is the time unit FreeRTOS actually uses internally.

_Example:_ Delay a task for 500 ms

```C++
vTaskDelay(pdMS_TO_TICKS(500));
```

## Periodic Tasks Using vTaskDelayUntil()

If our task needs to run at a **fixed rate**, we can use
`vTaskDelayUntil()` which blocks the calling task until a 
specific absolute tick count is reached, not "for N ticks from now".

```C++
void vTaskDelayUntil( TickType_t *pxPreviousWakeTime,
                      TickType_t  xTimeIncrement );
```

* `pxPreviousWakeTime`: Our reference time
* `xTimeIncrement`: period (in ticks)

Each time we call it:
1. FreeRTOS computes the next absolute wake-up time
2. Compares it to the current tick count
3. If the time is in the future, block the task until then
4. If already late, return immediately
5. Updates the reference time for the next cycle


So, `vTaskDelayUntil()` is the RTOS equivalent of doing a drift-free 
`millis()` scheduler loop in a single threaded environment.

But there are some key differences:

* Blocking vs polling
    - `millis(`) pattern: we poll time repeatedly (CPU keeps running your loop).
    - `vTaskDelayUntil()`: The task is put into the Blocked state and the CPU 
        can run other tasks or go idle.

    So it’s **more efficient** and more RTOS-friendly.

* Time base
    - `millis()` is milliseconds since boot (Arduino timebase).
    - `vTaskDelayUntil()` uses the FreeRTOS tick count (`xTaskGetTickCount()`), 
        which advances at `configTICK_RATE_HZ`.


_Example:_ Periodic Task

```C++
TickType_t lastWake = xTaskGetTickCount();

while (1) 
{
    doWork();
    vTaskDelayUntil(&lastWake, pdMS_TO_TICKS(1000));
}
```

## References
* [RTOS Fundamentals](https://www.freertos.org/Documentation/01-FreeRTOS-quick-start/01-Beginners-guide/01-RTOS-fundamentals)

* [Tasks and Co-routines](https://www.freertos.org/Documentation/02-Kernel/02-Kernel-features/01-Tasks-and-co-routines/00-Tasks-and-co-routines)

*Egon Teiniker, 2020-2025, GPL v3.0* 