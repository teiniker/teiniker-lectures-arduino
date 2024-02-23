# Free RTOS Tasks

In FreeRTOS, the term **task** is used instead of process or thread.

However, **FreeRTOS tasks are more like threads in traditional operating systems** 
because they share the same address space and can communicate with each other more directly.
Tasks in FreeRTOS do not have a separate memory space from each other, similar to threads
within the same process in a general-purpose operating system. 
This means all tasks share the same global memory.

FreeRTOS provides mechanisms for **task synchronization and communication**, such as 
**semaphores**, **queues**, and **mutexes**, which are typically used for thread 
synchronization in other operating systems.

The scheduler in FreeRTOS is designed to be **preemptive** or cooperative, 
giving developers control over task execution similar to thread scheduling in 
more complex operating systems.

In FreeRTOS, a task can exist in one of the following **states**:

![Tast States](figures/tskstate.gif)

* Running: When a task is actually executing it is said to be in the Running state. It is currently 
    utilising the processor. If the processor on which the RTOS is running only has a single core 
    then there can only be one task in the Running state at any given time.

* Ready: Ready tasks are those that are able to execute (they are not in the Blocked or Suspended 
    state) but are not currently executing because a different task of equal or higher priority is 
    already in the Running state.

* Blocked: A task is said to be in the Blocked state if it is currently waiting for either a temporal 
    or external event. For example, if a task calls vTaskDelay() it will block (be placed into the 
    Blocked state) until the delay period has expired - a temporal event. Tasks can also block to wait 
    for queue, semaphore, event group, notification or semaphore event. Tasks in the Blocked state 
    normally have a 'timeout' period, after which the task will be timeout, and be unblocked, even if 
    the event the task was waiting for has not occurred.

    Tasks in the Blocked state do not use any processing time and cannot be selected to enter the 
    Running state.

* Suspended: Like tasks that are in the Blocked state, tasks in the Suspended state cannot be 
    selected to enter the Running state, but tasks in the Suspended state do not have a time out. 
    Instead, tasks only enter or exit the Suspended state when explicitly commanded to do so through 
    the vTaskSuspend() and xTaskResume() API calls respectively.

The **FreeRTOS scheduler** ensures that tasks in the Ready or Running state will always be given 
processor (CPU) time in preference to tasks of a lower priority that are also in the ready state. 
In other words, **the task placed into the Running state is always the highest priority task 
that is able to run**.

_Example:_ [Blink and Alalog Read Tasks](tasks/blink-analog-read/) 


## References 

* [How to Multitask with FreeRTOS](https://youtu.be/WQGAs9MwXno)    
    * xTaskCreate()
    * vTaskDelay()

* [Manage FreeRTOS tasks - Suspend, Delay, Resume, Delete](https://youtu.be/jJaGRCgDo9s?si=1ZBI1Coe6A3cQmLx)
    * vTaskDelete()        
    * TaskHandle_t
    * vTaskSuspend()
    * vTaskSuspendAll()
    * vTaskResume()
    * xTaskResumeAll()


*Egon Teiniker, 2020-2024, GPL v3.0*     