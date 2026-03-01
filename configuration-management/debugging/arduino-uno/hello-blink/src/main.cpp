#include <Arduino.h>

#include"avr8-stub.h"   //!!!

void setup() 
{
    debug_init();       //!!!
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
    digitalWrite(LED_BUILTIN, HIGH);               
    delay(1000);                             
    digitalWrite(LED_BUILTIN, LOW);        
    delay(1000);  
}
