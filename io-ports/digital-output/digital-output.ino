/*
 * Digital Output (LED)
 * 
 * Pin 13: (on-board LED)
 * 
 * see: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
 *
 * Exercise: Change blink frequency to 5 HZ
 */

//#define LED_PIN  13
const int LED_PIN = 13;

void setup() 
{
  pinMode(LED_PIN, OUTPUT);        
}

void loop() 
{
  digitalWrite(LED_PIN, HIGH);      
  delay(100);                       
  
  digitalWrite(LED_PIN, LOW);       
  delay(100);                       
}
