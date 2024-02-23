# Example: Blinking LEDs

This example implements two tasks running cuncurrent using FreeRTOS.

* **Task Functions**: Each task in FreeRTOS is represented by a function. 
    The task will keep running whatever is inside its corresponding function in a loop.
```C++
void led1_task(void *pvParameter) 
{
    while(1) 
    {
        digitalWrite(LED1_PIN, HIGH);  // LED ON
        vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay for 500ms

        digitalWrite(LED1_PIN, LOW);  // LED OFF
        vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay for 500ms
    }
}
```

* **Task Creation**: The `xTaskCreatePinnedToCore()` function is used to create 
    a task and pin it to a specific core on the ESP32 (which is dual-core). 
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
    The parameters are:
    * Task Function: The function that the task should execute. In this case, either led1_task or led2_task.

    * Task Name: A descriptive name for the task. This is used for debugging purposes.

    * Stack Depth: The size of the stack for the task. This determines how much memory is allocated for the task's stack.

    * Parameters: Any parameters you want to pass to the task. In this example, we're not passing any parameters, so it's NULL.

    * Priority: The priority of the task. A higher number means higher priority.

    * Task Handle: A handle to the task. This can be used to refer to the task later (e.g., to delete it). We're not using this feature, so it's set to NULL.

    * Core Number: The core you want to pin the task to. The ESP32 is a dual-core processor, with cores numbered 0 and 1. In this case, both tasks are pinned to core 1.

* **Loop Function**: The `loop()` function is executed continuously after `setup()`. 
    In this case, it's essentially empty since the tasks are running independently in the background. We add a delay to prevent the `loop()` from running too quickly, which can be beneficial for power consumption and CPU usage.
```C++
void loop() 
{
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
```

Pinning tasks to a specific core is not strictly necessary, but it offers 
control and can help optimize performance for certain applications. 
The ESP32 is a dual-core microcontroller, which means it has two processing 
units that can run tasks in parallel. 

On the ESP32 with the Arduino framework, one core (usually Core 1) is often 
designated for user tasks (like the code you write), while the other core 
(usually Core 0) handles system tasks, such as WiFi and Bluetooth communication. 
By pinning your tasks to Core 1, you're ensuring they don't interfere with 
these system tasks.


## Accessing Resources

It's possible to use resources like Serial (UART) or the I2C bus inside a 
FreeRTOS task. However, there are important considerations to keep in mind:

* Concurrency Issues: If multiple tasks access the same resource (e.g., Serial 
    or I2C bus) simultaneously, it can lead to data corruption or unpredictable 
    behavior. To avoid this, you should use synchronization primitives like 
    semaphores or mutexes. For instance, if two tasks are trying to send data 
    over the same UART line, you'd use a semaphore to ensure that only one task 
    can access the UART at a time.

* Shared Data: If tasks share data (e.g., global variables), you need to ensure 
    that access to that data is thread-safe. This is especially crucial for 
    multi-byte or complex data types. Again, semaphores or mutexes can help here.

* Initial Setup: If a task uses a specific hardware resource, make sure that the 
    required initialization for that resource (like Serial.begin() for UART) is 
    done before the task starts running. This can be done in the setup() function.

* Task Priority: Be aware of task priorities when accessing shared resources. 
    A high-priority task might preempt a lower-priority task, which could lead 
    to issues if not managed properly.

* RTOS-Safe Libraries: Some libraries might not be safe to use in a multi-threaded 
    environment. If you're using third-party libraries to interact with hardware 
    resources inside a task, ensure that the library is designed to be used with 
    FreeRTOS or a similar RTOS.

* Blocking Calls: Some functions, like Serial.read() when waiting for data, can 
    block for an indefinite time. In a multitasking environment, this can prevent 
    other tasks from running. Consider using non-blocking versions of these 
    functions or timeouts.




## References
* [YouTube (Simply Explained): How to Multitask with FreeRTOS](https://youtu.be/WQGAs9MwXno)
