#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

// Queue for Serial output
QueueHandle_t serialQueue = NULL;
const size_t MSG_LEN = 128;          
const UBaseType_t QUEUE_DEPTH = 10; 

typedef struct 
{
  char text[MSG_LEN];
} serial_msg_t;


void task3(void *parameter)
{
  serial_msg_t msg;

  while(1) 
  {
    // Block until a message arrives, then print it
    if (xQueueReceive(serialQueue, &msg, portMAX_DELAY) == pdTRUE)
    {
        Serial.print(msg.text);
    }
  }
}


void task1(void *parameter) 
{
    serial_msg_t msg;

    while(1) 
    {
        // Build full message locally (no Serial here)
        msg.text[0] = '[';
        for (int i = 0; i < 80; i++)
        {
            msg.text[1 + i] = 'A';
        }
        msg.text[1 + 80] = ']';
        msg.text[1 + 81] = '\n';
        msg.text[1 + 82] = '\0';

        // Send to Task3 via queue (block if queue full)
        xQueueSend(serialQueue, &msg, portMAX_DELAY);

        vTaskDelay(pdMS_TO_TICKS(500)); 
    }
}

void task2(void *parameter) 
{
    while(1) 
    {
        serial_msg_t msg;
        msg.text[0] = '*';
        msg.text[1] = '\0';

        // Send to Task3 via queue (block if queue full)
        xQueueSend(serialQueue, &msg, portMAX_DELAY);

        vTaskDelay(pdMS_TO_TICKS(250));
    }
}


void setup() 
{
    Serial.begin(300);
    Serial.println("Queue - Serial");

    serialQueue = xQueueCreate(QUEUE_DEPTH, sizeof(serial_msg_t));
    if (serialQueue == NULL)
    {
        Serial.println("Failed to create Serial queue!");
        return;
    }

    xTaskCreate(task1, "Task1", 1024, NULL, 2, NULL);
    xTaskCreate(task2, "Task2", 1024, NULL, 2, NULL);
    xTaskCreate(task3, "Task3", 2048, NULL, 3, NULL);
}


void loop() 
{
    // Do nothing here
}
