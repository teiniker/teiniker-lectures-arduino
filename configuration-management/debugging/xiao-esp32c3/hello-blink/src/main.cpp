#include <Arduino.h>

const int LED_PIN = D2;     // external LED (XIAO ESP32C3 has no user LED)

void setup() 
{
    pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
    digitalWrite(LED_PIN, HIGH);               
    delay(1000);                             
    digitalWrite(LED_PIN, LOW);        
    delay(1000);  
}
