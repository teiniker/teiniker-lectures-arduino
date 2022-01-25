#include <Debounce.h>

const int BUTTON_PIN = 4;
const int LED_PIN = LED_BUILTIN;

Debounce Button(BUTTON_PIN, 50, false);

void setup() 
{
    Serial.begin(9600);  
  
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
   // Read the button state and write it to the LED.
   byte status = Button.read();
   digitalWrite(LED_PIN, status); 

   // Read the button count and write it to the Serial interface.
   unsigned int count = Button.count();
   Serial.println(count);       
}
