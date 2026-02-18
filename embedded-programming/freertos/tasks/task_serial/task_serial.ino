
void task1(void *parameter) 
{
    while(1) 
    {
        Serial.print("[");
        for(int i = 0; i < 80; i++) 
        {
            Serial.print("A");
            vTaskDelay(pdMS_TO_TICKS(5));            
        }
        Serial.println("]");
        
        vTaskDelay(pdMS_TO_TICKS(500)); 
    }
}

void task2(void *parameter) 
{
    while(1) 
    {
        Serial.print("*");
        vTaskDelay(pdMS_TO_TICKS(250));
    }
}


void setup() 
{
    Serial.begin(300);
    Serial.println("Task - Serial");
    xTaskCreate(task1, "Task1", 1024, NULL, 2, NULL);
    xTaskCreate(task2, "Task2", 1024, NULL, 2, NULL);
}


void loop() 
{
    // Do nothing here
}
