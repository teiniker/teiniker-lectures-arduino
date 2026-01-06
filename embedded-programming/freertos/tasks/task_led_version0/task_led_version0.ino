const int LED1_PIN = 2;
const int LED2_PIN = 3;

void led1_task(void *pvParameter) 
{
    // Setup  

    // Loop
    while(1) 
    {
        digitalWrite(LED1_PIN, HIGH);           // LED ON
        delay(500);                             // Delay for 500ms

        digitalWrite(LED1_PIN, LOW);            // LED OFF
        delay(500);                             // Delay for 500ms
    }   
}

void led2_task(void *pvParameter) 
{
    // Setup  

    // Loop
    while(1) 
    {
        digitalWrite(LED2_PIN, HIGH);           // LED ON
        delay(250);                             // Delay for 250ms

        digitalWrite(LED2_PIN, LOW);            // LED OFF
        delay(250);                             // Delay for 250ms
    }
}

void setup() 
{
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);

    // Create the FreeRTOS tasks
    xTaskCreate(led1_task, "LED1Task", 1024, NULL, 2, NULL);
    xTaskCreate(led2_task, "LED2Task", 1024, NULL, 2, NULL);
}

void loop() 
{
    // Do nothing here 
}
