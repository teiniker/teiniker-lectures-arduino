#include <Arduino_FreeRTOS.h>

struct led_pin 
{
    uint8_t pin;    // Arduino port pin
    uint32_t delay; // in ms
};


led_pin led_1 ={2, 250};
led_pin led_2 ={4, 500};

void setup() 
{
    // Create the FreeRTOS tasks
    xTaskCreate(led_task, "LED1Task", 128, &led_1, 2, NULL);
    xTaskCreate(led_task, "LED2Task", 128, &led_2, 2, NULL);
}

void loop() 
{
}

void led_task(void *pvParameter) 
{
    led_pin *led = (led_pin *) pvParameter;

    // setup
    pinMode(led->pin, OUTPUT);

    // loop
    while(1) 
    {
        digitalWrite(led->pin, HIGH);  // LED ON
        vTaskDelay(led->delay / portTICK_PERIOD_MS);  

        digitalWrite(led->pin, LOW);  // LED OFF
        vTaskDelay(led->delay / portTICK_PERIOD_MS);      
    }
}
