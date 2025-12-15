#include <Arduino_FreeRTOS.h>

void serial_task_1(void *pvParameter) 
{
    // Setup
    uint32_t counter = 0;

    // Loop
    while(1) 
    {
        Serial.print("Task 1: Counter = ");
        Serial.println(counter++);
        //vTaskDelay(250 / portTICK_PERIOD_MS);  
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
        //vTaskDelay(750 / portTICK_PERIOD_MS);  
    }
}

void setup() 
{
     Serial.begin(115200);

    // Create the FreeRTOS tasks
    xTaskCreate(serial_task_1, "Task-1", 128, NULL, 2, NULL);
    xTaskCreate(serial_task_2, "Task-2", 128, NULL, 2, NULL);
}

void loop() 
{
}
