#include <Arduino_FreeRTOS.h>
#include <queue.h>

QueueHandle_t messageQueue;

void setup() 
{
     Serial.begin(115200);

    // Create a queue capable of containing 5 pointer to char items
    messageQueue = xQueueCreate(5, sizeof(char*));
    if (messageQueue == NULL) 
    {
      Serial.println("Error creating the queue");
    }

    // Create the FreeRTOS tasks
    xTaskCreate(task_1, "Task-1", 128, NULL, 2, NULL);
    xTaskCreate(task_2, "Task-2", 128, NULL, 2, NULL);
    xTaskCreate(serial_task, "Logging", 128, NULL, 2, NULL);
}

void loop() 
{
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
        vTaskDelay(pdMS_TO_TICKS(250)); // Wait for 0.5 seconds
    }
}

void task_2(void *pvParameter) 
{
    char *message2 = "Hello from Task 2\n";
    while (1) 
    {
        if (xQueueSend(messageQueue, &message2, portMAX_DELAY) == pdPASS) 
        {
            // Successfully sent the message to the queue
        }
        vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 0.5 seconds
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

