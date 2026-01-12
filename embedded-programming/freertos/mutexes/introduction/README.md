# FreeRTOS Mutexes

## Mutual Exclusion

Mutual exclusion is a fundamental concept in concurrent programming that ensures 
**only one task can access a shared resource at a time**. This prevents 
**race conditions** and **data corruption** that can occur when multiple tasks 
try to modify the same resource simultaneously.

In FreeRTOS, a **Mutex** ('MUT'ual 'EX'clusion) provides a mechanism to 
implement mutual exclusion by acting as a lock around critical sections 
of code or shared resources:
* Only one task can hold the mutex at any given time
* Other tasks attempting to access the protected resource must wait until the 
    mutex is released
* The mutex owner is responsible for releasing it after completing operations 
    on the shared resource

When used for mutual exclusion the mutex acts like a **token that is used to 
guard a resource**. 
When a task wishes to access the resource it must first obtain ('take') the token. 
When it has finished with the resource it must 'give' the token back - allowing 
other tasks the opportunity to access the same resource.

Mutexes permit a **block time** to be specified. The block time indicates the maximum 
number of 'ticks' that a task should enter the Blocked state when attempting to 
'take' a mutex if the mutex is not immediately available.

Mutexes employ **priority inheritance**. This means that if a high priority task 
blocks while attempting to obtain a mutex (token) that is currently held by a lower
priority task, then the priority of the task holding the token is temporarily raised 
to that of the blocking task. 
This mechanism is designed to ensure the higher priority task is kept in the 
blocked state for the shortest time possible, and in so doing minimise the 
'priority inversion' that has already occurred.

Mutexes should **not be used from an interrupt** because:
* They include a priority inheritance mechanism which only makes sense if the 
    mutex is given and taken from a task, not an interrupt.

* An interrupt cannot block to wait for a resource that is guarded by a mutex 
    to become available.


## Recursive Mutexes

A mutex used recursively can be 'taken' repeatedly by the owner. The mutex doesn't 
become available again until the owner has called `xSemaphoreGiveRecursive()` for 
each successful `xSemaphoreTakeRecursive()` request.

For example, if a task successfully 'takes' the same mutex 5 times then the mutex 
will not be available to any other task until it has also 'given' the mutex back 
exactly five times.


## FreeRTOS API

* **SemaphoreHandle_t**: A FreeRTOS handle to a semaphore object.
    Mutexes are implemented using the semaphore API, so the type is still 
    `SemaphoreHandle_t`.

* **xSemaphoreCreateMutex()**: Creates a mutex (mutual exclusion lock) and returns 
    a handle by which the created mutex can be referenced. 

    ```C++
    SemaphoreHandle_t xSemaphoreCreateMutex(void);
    ```

    - If the mutex was created successfully then a handle to the 
        created mutex is returned.

    - If the mutex was not created because the memory required to hold the mutex 
        could not be allocated then `NULL` is returned.

* **xSemaphoreTake()**: Macro to obtain a semaphore or mutex. The mutex must have 
    previously been created with a call to `xSemaphoreCreateMutex()`.

    ```C++
     xSemaphoreTake(SemaphoreHandle_t xSemaphore, TickType_t xTicksToWait);
    ```

    - `xSemaphore`: A handle to the mutex being taken (obtained when the 
        mutex was created).

    - `TicksToWait`: The time in ticks to wait for the mutex to become available. 
        The macro `portTICK_PERIOD_MS` can be used to convert this to a real time.
        
        Specifying the block time as `portMAX_DELAY` will cause the task to block 
        indefinitely (without a timeout).
        
        A block time of zero can be used to poll the mutex.
     

* **xSemaphoreGive()**: Macro to release a semaphore or mutex. The mutex must 
    have previously been created with a call to `xSemaphoreCreateMutex()`.

    ```C++
    xSemaphoreGive(SemaphoreHandle_t xSemaphore);
    ```
    
    - `xSemaphore`: A handle to the mutex being released. This is the handle 
        returned when the mutex was created. 

    - Returns `pdTRUE` if the mutex was released and `pdFALSE` if an error 
        occurred.


## References

* [YouTube (Digi-Key Electronics): Part 6: Mutex](https://youtu.be/I55auRpbiTs?si=57p6FpE6H6TNtaoJ)

* [FreeRTOS Mutexes](https://www.freertos.org/Real-time-embedded-RTOS-mutexes.html)

*Egon Teiniker, 2020-2025, GPL v3.0* 