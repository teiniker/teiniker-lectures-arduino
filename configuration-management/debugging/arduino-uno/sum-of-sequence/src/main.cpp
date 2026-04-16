#include <Arduino.h>
#include"avr8-stub.h"   //!!!

void setup() 
{
    debug_init();       //!!!
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
    uint8_t n = 10;
    uint32_t sum = 0;
    
    digitalWrite(LED_BUILTIN, HIGH);               
    for (uint8_t i = 1; i <= n; i++) 
    {
        sum += i;
    }
    digitalWrite(LED_BUILTIN, LOW);        
    delay(100);  
}
