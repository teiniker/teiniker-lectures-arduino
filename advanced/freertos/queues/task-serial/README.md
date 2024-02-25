# Example: Serial Task Using Queue 

This example demonstrates a basic pattern for serial communication in a 
multitasking environment.

This approach ensures that **only one task accesses the serial port at a time**, 
avoiding synchronization issues.

* **Task 1 and Task 2**: These tasks generate some data or messages and send 
    them to the queue.
* **Serial Task**: This task waits for messages on the queue. When a message is 
    received, it prints the message to the serial port.
* **Queue**: A FreeRTOS queue is used for communication between the tasks and the 
serial task.


_Example:_ Using a single task to receive messages from a queue and write them to Serial
```C++
QueueHandle_t messageQueue;

void setup() 
{
    Serial.begin(115200);

    messageQueue = xQueueCreate(5, sizeof(char*));
    if (messageQueue == NULL) 
    {
      Serial.println("Error creating the queue");
    }
    //...
}

void task_1(void *pvParameter) 
{
    char *message2 = "Hello from Task 1\n";

    while(1) 
    {
        if (xQueueSend(messageQueue, &message2, portMAX_DELAY) == pdPASS) 
        {
            // Successfully sent the message to the queue
        }
        vTaskDelay(pdMS_TO_TICKS(250)); 
    }
}

void serial_task(void *pvParameter) 
{
    // Setup
    char *receivedMessage;
    
    // Loop
    while(1) 
    {
        if (xQueueReceive(messageQueue, &receivedMessage, portMAX_DELAY) == pdPASS) 
        {
            Serial.print(receivedMessage);
        }
    }
}
```

* **Queue Creation**: A queue is created with `xQueueCreate()` to hold pointers to characters. 
    This is because we're sending string literals (which are essentially constant character arrays) 
    from the tasks to the serial task.
* **Sending Messages**: task1 and task2 send pointers to their messages to the queue using `xQueueSend()`.
* **Receiving Messages**: The serialTask waits for messages on the queue with `xQueueReceive()` and 
    prints any received messages using `Serial.print()`.
* **Task Priorities**: The serial task might have a higher priority to ensure timely processing of 
    messages, but this depends on your specific requirements.


*Egon Teiniker, 2020-2024, GPL v3.0*    
