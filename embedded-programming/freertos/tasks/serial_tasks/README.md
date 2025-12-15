# Accessing Serial from two Tasks

In the context of the ESP32 and its use of FreeRTOS, the hardware **Serial is already thread-safe**.
This means that you can use `Serial.print()` or other related functions from multiple tasks without 
the need for a mutex to guard the serial resource.

This thread-safety is achieved through internal locking mechanisms in the ESP32's hardware serial implementation. When one task is using the serial port, other tasks trying to access it will be 
blocked until the first task finishes its operation.

```C++
void task1(void *parameter) 
{
    while(1) 
    {
        Serial.println("Task 1");    
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
```

There are some considerations to keep in mind:

* Atomic Operations: Even though individual Serial calls (like Serial.print()) are thread-safe, 
    **a sequence of calls may not be atomic**. 

  In a multitasking environment, another task could potentially interrupt between these calls, causing mixed output on the serial monitor. If you want to ensure atomicity for a sequence of operations, then using a mutex or semaphore to protect the entire sequence would be appropriate.

* Performance: If you have multiple tasks frequently accessing the serial port, it could lead 
    to contention and tasks being blocked, which may impact the real-time performance of your 
    system.

* Logical Consistency: For logging or debugging purposes, it's often desirable to have entire 
    messages or data blocks from one task printed together, without being interspersed with 
    messages from other tasks. Mutexes can help maintain this logical consistency.


## References


