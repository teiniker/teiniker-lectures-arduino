# Accessing Serial from two Tasks via Queue

In FreeRTOS, a queue provides a safe and deterministic way for tasks 
to **exchange data and synchronize execution** without sharing memory directly.

It **decouples producers from consumers**: one task can generate data and block 
when the queue is full, while another task processes data and blocks when the 
queue is empty, eliminating busy-waiting and most race conditions.

Because queue operations are thread-safe and copy data, **queues simplify concurrency**, 
improve system robustness, and **make task interactions easier** to reason about 
than using shared variables with mutexes.

## Implementation

### Define Queue and Message Type

```C++
QueueHandle_t serialQueue = NULL;
const size_t MSG_LEN = 128;
const UBaseType_t QUEUE_DEPTH = 10;

typedef struct 
{
    char text[MSG_LEN];
} serial_msg_t;
```

* `serialQueue`: A FreeRTOS queue handle which holds the messages to be printed.

* `MSG_LEN`: The maximum length (in bytes) of one queued message (including '\0').

* `QUEUE_DEPTH`: How many messages can be waiting in the queue at once.

* `serial_msg_t`: The item type stored in the queue: a fixed-size struct 
    containing a fixed-size char buffer.
    - FreeRTOS queues store fixed-size items. Here, each item is sizeof(serial_msg_t) bytes.
    - When we send a `serial_msg_t`, FreeRTOS copies the whole struct into the queue storage.


### Setup

```C++
void setup()
{
    //...
    serialQueue = xQueueCreate(QUEUE_DEPTH, sizeof(serial_msg_t));
    if (serialQueue == NULL)
    {
        Serial.println("Failed to create Serial queue!");
        return;
    }
    //...
}
```

* `xQueueCreate(10, sizeof(serial_msg_t))`: Allocates a queue that can store 10 
    full `serial_msg_t` items.


### Only One Task Prints to Serial

This task reads messages from the queue and writes them to `Serial`.
When the queue is empty, the task blocks until a new message can be read.

This task has exclusive access to `Serial`.

```C++
void task3(void *parameter)
{
    serial_msg_t msg;

    while(1) 
    {
        if (xQueueReceive(serialQueue, &msg, portMAX_DELAY) == pdTRUE)
        {
            Serial.print(msg.text);
        }
    }
}
```

* `msg`: A local buffer (on Task3’s stack) that receives one queue item at a time.

* `xQueueReceive(..., portMAX_DELAY)` means:
    - **Block forever until a message is available**.
    - When one arrives, FreeRTOS copies the queued `serial_msg_t` into `msg`.

* `Serial.print(msg.text)`: Outputs exactly the text the producer task sent.

Because **only Task3 touches Serial**, we avoid garbled output and don’t need 
a mutex:

```
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
*[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
...
```

### Sending Task

Tasks can construct a message and write it to the queue.

If the queue is full, the writing task blocks until the message can be written.

```C++
void task1(void *parameter)
{
    serial_msg_t msg;

    while(1)
    {
        msg.text[0] = '[';
        for (int i = 0; i < 80; i++)
        {
            msg.text[1 + i] = 'A';
        }
        msg.text[1 + 80] = ']';
        msg.text[1 + 81] = '\n';
        msg.text[1 + 82] = '\0';

        xQueueSend(serialQueue, &msg, portMAX_DELAY);

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
```

* `serial_msg_t msg` is allocated once (on Task1’s stack) and reused each loop.

* `xQueueSend(..., portMAX_DELAY)`: Copies the whole struct into the queue.
    If the queue is full, **Task1 will block until there’s space**.


## References

* [YouTube (Digi-Key Electronics): Part 5 - Queue](https://youtu.be/pHJ3lxOoWeI?si=XhCTe3GFLu9p_Vv0)

* [FreeRTOS: Queue Management](https://www.freertos.org/Documentation/02-Kernel/04-API-references/06-Queues/00-QueueManagement)


*Egon Teiniker, 2020-2025, GPL v3.0* 
