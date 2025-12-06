# FreeRTOS Mutexes

Mutexes are binary semaphores that include a priority inheritance mechanism
which are used for implementing simple **mutual exclusion** 
(hence 'MUT'ual 'EX'clusion).

When used for mutual exclusion the mutex acts like a **token that is used to guard a resource**. 
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
This mechanism is designed to ensure the higher priority task is kept in the blocked state for the shortest time possible, and in so doing minimise the 'priority inversion' that has already occurred.

Mutexes should **not be used from an interrupt** because:
* They include a priority inheritance mechanism which only makes sense if the 
    mutex is given and taken from a task, not an interrupt.

* An interrupt cannot block to wait for a resource that is guarded by a mutex 
    to become available.

## Recursive Mutexes

A mutex used recursively can be 'taken' repeatedly by the owner. The mutex doesn't 
become available again until the owner has called xSemaphoreGiveRecursive() for 
each successful xSemaphoreTakeRecursive() request.

For example, if a task successfully 'takes' the same mutex 5 times then the mutex 
will not be available to any other task until it has also 'given' the mutex back 
exactly five times.

## References

* [FreeRTOS Mutexes](https://www.freertos.org/Real-time-embedded-RTOS-mutexes.html)

*Egon Teiniker, 2020-2025, GPL v3.0* 