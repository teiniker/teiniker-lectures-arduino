#include <Arduino_FreeRTOS.h>

const uint8_t LED1_PIN = 2;
const uint8_t LED2_PIN = 6;

void setup() 
{
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);

    // Create the FreeRTOS tasks
    xTaskCreate(led1_task, "LED1Task", 128, NULL, 2, NULL);
    xTaskCreate(led2_task, "LED2Task", 128, NULL, 2, NULL);
}

void loop() 
{
}

void led1_task(void *pvParameter) 
{
    while(1) 
    {
        digitalWrite(LED1_PIN, HIGH);  
        vTaskDelay(500 / portTICK_PERIOD_MS);  

        digitalWrite(LED1_PIN, LOW);  
        vTaskDelay(500 / portTICK_PERIOD_MS);  
    }
}

void led2_task(void *pvParameter) 
{
    while(1) 
    {
        digitalWrite(LED2_PIN, HIGH);  
        vTaskDelay(250 / portTICK_PERIOD_MS);  

        digitalWrite(LED2_PIN, LOW);  
        vTaskDelay(250 / portTICK_PERIOD_MS);  
    }
}
