# Example: Multiple Tasks Using Serial 

Using `Serial.print()` within a task in FreeRTOS on an Arduino Uno board is 
technically possible, but it comes with considerations regarding synchronization 
and concurrency. 

_Example:_ Two tasks using Serial 

```C++
void task_1(void *pvParameter) 
{
    // Setup
    uint32_t counter = 0;

    // Loop
    while(1) 
    {
        Serial.print("Task 1: Counter = ");
        Serial.println(counter++);
    }
}

void serial_task_2(void *pvParameter) 
{
    // Setup
    uint32_t counter = 0;

    // Loop
    while(1) 
    {
        Serial.print("Task 2: Counter = ");
        Serial.println(counter++);
    }
}
```

**The Arduino Serial library is not inherently thread-safe**, which means that if 
we have multiple tasks that attempt to use `Serial.print()` at the same time, we 
might encounter garbled output or other synchronization issues.

_Example:_ Using Serial in multiple tasks leads to garbled output 
```
Task 2: Counter = 570
Task 2: Counter = 571
Task 2: Counter = 572
Task 2: Counter = 573
Task 2: Counter 1: Counter = 577
Task 1: Counter = 578
```

The best way to use Serial communication involves ensuring thread safety and maintaining 
efficient **task synchronization**. The goal is to **prevent concurrent access to the 
Serial port from multiple tasks**, which can lead to garbled output or data corruption. 

Here are some strategies and best practices for using Serial:

* **Mutexes for Protection**:
    If a dedicated serial task is not feasible or if direct Serial access is required 
    from multiple tasks, use a **mutex (mutual exclusion semaphore)** to protect access 
    to the Serial port. A task must acquire the mutex before executing any Serial operations 
    and release it afterward. This ensures that only one task at a time can perform Serial 
    operations.    

* **Dedicated Serial Task**:
    We create a dedicated task for handling all Serial communications. This task is 
    responsible for sending and receiving data over the serial port. Other tasks should 
    communicate with the serial task using thread-safe mechanisms provided by the RTOS, 
    such as queues, semaphores, or event groups, to request Serial operations.

* **Use of Queues**: 
    Queues are particularly effective for serial communication. Tasks that need to print 
    messages to the serial port can send these messages to a queue. The dedicated serial 
    task then reads from this queue and handles the actual `Serial.print()` calls. 
    This method serializes access to the Serial port and prevents access conflicts.    

* **Logging Task with Message Aggregation**:
    In systems with heavy diagnostic or logging output, consider implementing a logging 
    task that aggregates messages from various tasks before sending them out through the 
    Serial port. This can reduce the number of Serial operations and allow for more organized 
    output, such as adding timestamps or task identifiers to messages.    

The dedicated serial task and queue approach is often the best balance between simplicity 
and efficiency. It encapsulates all Serial communication within a single task, reducing the 
risk of concurrency issues, and uses RTOS features to safely pass messages between tasks.

*Egon Teiniker, 2020-2024, GPL v3.0*    
