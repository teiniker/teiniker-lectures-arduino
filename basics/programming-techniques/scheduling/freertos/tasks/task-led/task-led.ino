#include <Arduino_FreeRTOS.h>

const uint8_t LED1_PIN = 2;
const uint8_t LED2_PIN = 6;

void setup() 
{
    // Create the FreeRTOS tasks
    xTaskCreate(led1_task, "LED1Task", 128, NULL, 1, NULL);
    xTaskCreate(led2_task, "LED2Task", 128, NULL, 2, NULL);
}

void loop() 
{
}

void led1_task(void *pvParameter) 
{
    // setup
    pinMode(LED1_PIN, OUTPUT);

    // loop
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
    // setup
    pinMode(LED2_PIN, OUTPUT);

    // loop
    while(1) 
    {
        digitalWrite(LED2_PIN, HIGH);  
        vTaskDelay(250 / portTICK_PERIOD_MS);  

        digitalWrite(LED2_PIN, LOW);  
        vTaskDelay(250 / portTICK_PERIOD_MS);  
    }
}
