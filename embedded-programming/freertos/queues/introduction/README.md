# Queues

Queues are the primary form of **intertask communications**. They can be 
used to send messages between tasks, and between interrupts and tasks. 
In most cases they are used as thread safe **FIFO (First In First Out) 
buffers** with new data being sent to the back of the queue.

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

When a task attempts to **read from an empty queue** the task will be placed 
into the **Blocked state** (so it is not consuming any CPU time and other tasks 
can run) until either data becomes available on the queue, or the block time expires.

When a task attempts to **write to a full queue** the task will be placed into 
the **Blocked state** (so it is not consuming any CPU time and other tasks can run) 
until either space becomes available in the queue, or the block time expires.

If more than one task block on the same queue then the task with the highest 
priority will be the task that is unblocked first.


## FreeRTOS API 

* **QueueHandle_t**: It is a pointer used by FreeRTOS to refer to a specific queue.
    FreeRTOS uses the handle to **know which queue** we are sending to or receiving 
    from.

* **xQueueCreate()**: Creates a new queue and returns a handle by which 
    the queue can be referenced.

    ```C++
    QueueHandle_t xQueueCreate(UBaseType_t uxQueueLength, UBaseType_t uxItemSize);
    ```

    - `uxQueueLength`: The maximum number of items the queue can hold at any one time.

    - `uxItemSize`: The size, in bytes, required to hold each item in the queue.

        **Items are queued by copy**, not by reference, so this is the number 
        of bytes that will be copied for each queued item. Each item in the 
        queue must be the same size.

    - If the queue is created successfully then a handle to the created queue 
        is returned. If the memory required to create the queue could not be 
        allocated then `NULL` is returned.


* **xQueueReceive()**: Receive an item from a queue. 
    The **item is received by copy** so a buffer of adequate size must be provided. 
    The number of bytes copied into the buffer was defined when the queue was created.

    ```C++
    BaseType_t xQueueReceive(
                            QueueHandle_t xQueue,
                            void *pvBuffer,
                            TickType_t xTicksToWait
    );
    ```

    - `xQueue`: The handle to the queue from which the item is to be received.

    - `pvBuffer`: Pointer to the buffer into which the received item will be copied.

    - `xTicksToWait`: The maximum amount of time the task should block waiting for 
        an item to receive should the queue be empty at the time of the call.

        The time is defined in tick periods so the macro `portTICK_PERIOD_MS`
        should be used to convert to real time if this is required.

        Specifying the block time as `portMAX_DELAY` will cause the task to 
        block indefinitely (without a timeout).

        Setting `xTicksToWait` to 0 will cause the function to return immediately 
        if the queue is empty.
    
    - Returns `pdPASS` if an item was successfully received from the queue, 
        `errQUEUE_EMPTY` otherwise.

* **xQueueSend()**: Post an item on a queue. The **item is queued by copy**, 
    not by reference. 

    ```C++
    BaseType_t xQueueSend(
                            QueueHandle_t xQueue,
                            const void * pvItemToQueue,
                            TickType_t xTicksToWait
                        );
    ```

    - `xQueue`: The handle to the queue on which the item is to be posted.

    - `pvItemToQueue`: A pointer to the item that is to be placed on the 
        queue. The size of the items the queue will hold was defined when 
        the queue was created, so this many bytes will be copied from 
        `pvItemToQueue` into the queue storage area.

    - `xTicksToWait`: The maximum amount of time the task should block waiting 
        for space to become available on the queue, should it already be full. 

        The time is defined in tick periods so the constant `portTICK_PERIOD_MS`
        should be used to convert to real time if this is required.

        Specifying the block time as `portMAX_DELAY` will cause the task to 
        block indefinitely (without a timeout).

        The call will return immediately if the queue is full and `xTicksToWait`
        is set to 0. 

    - Returns `pdPASS` if the item was successfully posted, `errQUEUE_FULL` 
        otherwise.


## References

* [YouTube (Digi-Key Electronics): Part 5 - Queue](https://youtu.be/pHJ3lxOoWeI?si=XhCTe3GFLu9p_Vv0)

* [FreeRTOS Queues](https://www.freertos.org/Embedded-RTOS-Queues.html)

*Egon Teiniker, 2020-2025, GPL v3.0* 