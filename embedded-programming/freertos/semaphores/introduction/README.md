# FreeRTOS Semaphores 

## Binary Semaphores

Binary semaphores are used for both **mutual exclusion** and **synchronisation purposes**.

Binary semaphores and mutexes are very similar but have some subtle differences: Mutexes include a priority inheritance mechanism, binary semaphores do not. 

This makes **binary semaphores** the better choice for **implementing synchronisation** (between tasks or between tasks and an interrupt), and **mutexes** the better choice for **implementing simple mutual exclusion**. 

We can think of a binary semaphore as a queue that can only hold one item. 
The queue can therefore only be empty or full (hence binary).
Tasks and interrupts using the queue don't care what the queue holds - they only 
want to know if the queue is empty or full. This mechanism can be exploited to synchronise (for example) a task with an interrupt.

Semaphore API functions permit a block time to be specified. The block time indicates 
the maximum number of 'ticks' that a task should enter the Blocked state when attempting
to 'take' a semaphore, should the semaphore not be immediately available. 
If more than one task blocks on the same semaphore then the task with the highest 
priority will be the task that is unblocked the next time the semaphore becomes 
available.


## Counting Semaphores

Just as binary semaphores can be thought of as queues of length one, counting 
semaphores can be thought of as **queues of length greater than one**. 

Again, users of the semaphore are not interested in the data that is stored in 
the queue - just whether or not the queue is empty or not.

Counting semaphores are typically used for two things:
* Counting events:
    In this usage scenario an event handler will 'give' a semaphore each time 
    an event occurs (incrementing the semaphore count value), and a handler 
    task will 'take' a semaphore each time it processes an event (decrementing 
    the semaphore count value). 
    The count value is therefore the difference between the number of events 
    that have occurred and the number that have been processed. In this case 
    it is desirable for the count value to be zero when the semaphore is created.


* Resource management:
    In this usage scenario an event handler will 'give' a semaphore each time 
    an event occurs (incrementing the semaphore count value), and a handler 
    task will 'take' a semaphore each time it processes an event (decrementing 
    the semaphore count value). The count value is therefore the difference 
    between the number of events that have occurred and the number that have 
    been processed. In this case it is desirable for the count value to be 
    zero when the semaphore is created.



## References 
* [FreeRTOS Binary Semaphores](https://www.freertos.org/Embedded-RTOS-Binary-Semaphores.html)
* [FreeRTOS Counting Semaphores](https://www.freertos.org/Real-time-embedded-RTOS-Counting-Semaphores.html)