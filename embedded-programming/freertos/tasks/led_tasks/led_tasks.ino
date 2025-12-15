#define LED1_PIN 2
#define LED2_PIN 4

void led1_task(void *pvParameter) 
{
    while(1) 
    {
        digitalWrite(LED1_PIN, HIGH);  // LED ON
        vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay for 500ms

        digitalWrite(LED1_PIN, LOW);  // LED OFF
        vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay for 500ms
    }
}

void led2_task(void *pvParameter) 
{
    while(1) 
    {
        digitalWrite(LED2_PIN, HIGH);  // LED ON
        vTaskDelay(250 / portTICK_PERIOD_MS);  // Delay for 250ms

        digitalWrite(LED2_PIN, LOW);  // LED OFF
        vTaskDelay(250 / portTICK_PERIOD_MS);  // Delay for 250ms
    }
}

void setup() 
{
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);

    // Create the FreeRTOS tasks
    xTaskCreatePinnedToCore(led1_task, "LED1Task", 1024, NULL, 2, NULL, 1);
    xTaskCreatePinnedToCore(led2_task, "LED2Task", 1024, NULL, 2, NULL, 1);
}

void loop() 
{
    // Just a delay to prevent the loop from running wild.
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
