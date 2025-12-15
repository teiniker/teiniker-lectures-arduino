# Queues

Queues are the primary form of intertask communications. They can be 
used to send messages between tasks, and between interrupts and tasks. 
In most cases they are used as thread safe FIFO (First In First Out) 
buffers with new data being sent to the back of the queue.

**Messages are sent** through queues **by copy**, meaning the data (which can 
be a pointer to larger buffers) is itself copied into the queue rather 
than the queue always storing just a reference to the data:
* Small messages that are already contained in C variables (integers, 
    small structures, etc.) can be sent into a queue directly. 

* When the size of a message reaches a point where it is not practical 
    to copy the entire message into the queue byte for byte, define the 
    queue to hold pointers and copy just a pointer to the message into 
    the queue instead.

* The kernel takes complete responsibility for allocating the memory 
    used as the queue storage area.

* Variable sized messages can be sent by defining queues to hold structures 
    that contain a member that points to the queued message, and another 
    member that holds the size of the queued message.

* A single queue can be used to receive different message types, and 
    messages from multiple locations, by defining the queue to hold a 
    structure that has a member that holds the message type, and another 
    member that holds the message data (or a pointer to the message data).

* The queue storage area is only accessed by the RTOS (with full privileges).


## Blocking on Queues

When a task attempts to **read from an empty queue** the task will be placed into the **Blocked state** (so it is not consuming any CPU time and other tasks can run) until either data becomes available on the queue, or the block time expires.

When a task attempts to **write to a full queue** the task will be placed into 
the **Blocked state** (so it is not consuming any CPU time and other tasks can run) 
until either space becomes available in the queue, or the block time expires.

If more than one task block on the same queue then the task with the highest priority will be the task that is unblocked first.



## References

* [FreeRTOS Queues](https://www.freertos.org/Embedded-RTOS-Queues.html)
