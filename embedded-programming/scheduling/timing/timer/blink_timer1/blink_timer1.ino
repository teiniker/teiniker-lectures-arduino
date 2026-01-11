#include <TimerOne.h>

const int ledPin = 2;

// volatile means that this variable can be changed in an interrupt
volatile bool ledState = false;

void ISR_blink_led() 
{
  ledState = !ledState;
}


void setup() 
{
  pinMode(ledPin, OUTPUT);

  // Initialize Timer1 to trigger every 1,000,000 microseconds (1 second)
  Timer1.initialize(1000000); 
  
  // Attach the ISR function to the timer
  Timer1.attachInterrupt(ISR_blink_led); 
}


void loop() 
{
  digitalWrite(ledPin, ledState);
}