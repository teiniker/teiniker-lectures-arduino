
void task1(void *parameter) 
{
    while(1) 
    {
//        Serial.println("{");    
        Serial.println("Task 1");
//        Serial.println("}");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void task2(void *parameter) 
{
    while(1) 
    {
        Serial.println("Task 2");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}


void setup() 
{
    Serial.begin(115200);

    xTaskCreate(task1, "Task1", 1024, NULL, 1, NULL);
    xTaskCreate(task2, "Task2", 1024, NULL, 1, NULL);
}


void loop() 
{
    // Just a delay to prevent the loop from running wild.
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
