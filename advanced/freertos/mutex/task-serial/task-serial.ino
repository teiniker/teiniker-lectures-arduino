#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t mutex;

void setup() 
{
     Serial.begin(115200);

    mutex = xSemaphoreCreateMutex();
    if (mutex != NULL) 
    {
      Serial.println("Mutex created");
    }

    // Create the FreeRTOS tasks
    xTaskCreate(task_1, "Task-1", 128, NULL, 2, NULL);
    xTaskCreate(task_2, "Task-2", 128, NULL, 2, NULL);
}

void loop() 
{
}

void task_1(void *pvParameter) 
{
    const char *message1 = "Hello from Task 1\n";

    while(1) 
    {
        // Try to take the mutex. Wait forever until it's available.
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) 
        {
            Serial.print(message1);
            // Release the mutex after using the shared resource.
            xSemaphoreGive(mutex);
        }
        //vTaskDelay(250 / portTICK_PERIOD_MS); // Wait for 0.25 seconds before sending again.
    }
}

void task_2(void *pvParameter) 
{
    const char *message2 = "Hello from Task 2\n";

    while(1) 
    {
        // Try to take the mutex. Wait forever until it's available.
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) 
        {
            Serial.print(message2);
            // Release the mutex after using the shared resource.
            xSemaphoreGive(mutex);
        }
        //vTaskDelay(500 / portTICK_PERIOD_MS); // Wait for 0.5 seconds before sending again.
    }
}
