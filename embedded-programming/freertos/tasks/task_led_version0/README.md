# Example: Blinking LEDs Using delay()

This example creates two tasks running concurrent using FreeRTOS.

## Create a Normal Dynamic Task: xTaskCreate()

* **Task Functions**: Each task in FreeRTOS is represented by a function. 
    The task will keep running whatever is inside its corresponding function in a loop.

```C++
void led1_task(void *pvParameter) 
{
    // Loop
    while(1) 
    {
        digitalWrite(LED1_PIN, HIGH);           // LED ON
        vTaskDelay(500 / portTICK_PERIOD_MS);   // Delay for 500ms

        digitalWrite(LED1_PIN, LOW);            // LED OFF
        vTaskDelay(500 / portTICK_PERIOD_MS);   // Delay for 500ms
    }
}
```

* **Task Creation**: The `xTaskCreate()` function is used to create 
    a task.
    
```C++    
xTaskCreate(
    led1_task,      // Task Function 
    "LED1Task",     // Task Name
    1024,           // Stack Depth 
    NULL,           // Parameters 
    2,              // Priority 
    NULL            // Task Handle
);
```

* **Task Function**: The function that the task should execute. In this 
    case, either led1_task or led2_task.

* **Task Name**: A descriptive name for the task. This is used for 
    debugging purposes.

* **Stack Depth**: The size of the stack for the task. This determines 
    how much memory is allocated for the task's stack.

* **Parameters**: Any parameters you want to pass to the task. In this 
    example, we're not passing any parameters, so it's NULL.

* **Priority**: The priority of the task. A higher number means higher 
    priority.

* **Task Handle**: A handle to the task. This can be used to refer to the 
    task later (e.g., to delete it). We're not using this feature, so 
    it's set to NULL.


## Create a Task Pinned to a Core: xTaskCreatePinnedToCore()

On **dual-core ESP32 chips**, we can pin a task to core 0 or 1.

ESP32-C6 is single-core, so _pinning_ isn’t really useful there, 
but the function may still exist in the Arduino core for compatibility 
(it effectively ends up on the only core).


* **Task Creation**: The `xTaskCreatePinnedToCore()` function is used 
    to create a task and pin it to a specific core on the ESP32 
    (which is dual-core).
    
```C++    
xTaskCreatePinnedToCore(
    led1_task,      // Task Function 
    "LED1Task",     // Task Name
    1024,           // Stack Depth 
    NULL,           // Parameters 
    2,              // Priority 
    NULL,           // Task Handle
    1               // Core Number
);
```

* **Core Number**: The core we want to pin the task to. The ESP32 is 
a dual-core processor, with cores numbered 0 and 1. In this case, both 
tasks are pinned to core 1.


## Loop Function

The `loop()` function is executed continuously after `setup()`. 
In this case, it's empty since the tasks are running independently 
in the background.

```C++
void loop() 
{
}
```


## Concurrent Execution

In the end, we have **multiple tasks running concurrently** (each task has its 
own loop logic). These tasks run independently of each other, but they can access 
shared resources (variables, interfaces, etc.), which can lead to significant 
problems.

It's possible to use resources like Serial (UART) or the I2C bus inside a 
FreeRTOS task. However, there are important considerations to keep in mind:

* **Concurrency Issues**: If multiple tasks access the same resource (e.g., Serial 
    or I2C bus) simultaneously, it can lead to data corruption or unpredictable 
    behavior. To avoid this, you should use **synchronization primitives** like 
    semaphores or mutexes. For instance, if two tasks are trying to send data 
    over the same UART line, you'd use a semaphore to ensure that only one task 
    can access the UART at a time.

* **Shared Data**: If tasks share data (e.g., global variables), we need to ensure 
    that access to that data is thread-safe. This is especially crucial for 
    multi-byte or complex data types. Again, semaphores or mutexes can help here.

* **Initial Setup**: If a task uses a specific hardware resource, make sure that the 
    required initialization for that resource (like `Serial.begin()` for UART) is 
    done before the task starts running. This can be done in the `setup()` function.

* **Task Priority**: Be aware of task priorities when accessing shared resources. 
    A high-priority task might preempt a lower-priority task, which could lead 
    to issues if not managed properly.

* **RTOS-Safe Libraries**: Some libraries might not be safe to use in a multi-threaded 
    environment. If you're using third-party libraries to interact with hardware 
    resources inside a task, ensure that the library is designed to be used with 
    FreeRTOS or a similar RTOS.

* **Blocking Calls**: Some functions, like `Serial.read()` when waiting for data, 
    can block for an indefinite time. In a multitasking environment, this can prevent 
    other tasks from running. Consider using non-blocking versions of these functions 
    or timeouts.


## References
* [RTOS Fundamentals](https://www.freertos.org/Documentation/01-FreeRTOS-quick-start/01-Beginners-guide/01-RTOS-fundamentals)

* [Tasks and Co-routines](https://www.freertos.org/Documentation/02-Kernel/02-Kernel-features/01-Tasks-and-co-routines/00-Tasks-and-co-routines)

*Egon Teiniker, 2020-2025, GPL v3.0* 