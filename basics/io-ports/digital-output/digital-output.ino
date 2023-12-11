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
   Serial.begin(115200);     
}

void print(int8_t value, bool flag)
{
  Serial.println(value);
  Serial.println(flag);
}


void loop() 
{
  digitalWrite(LED_PIN, HIGH);      
  delay(1000);                       
  
  print(7.6, false);
  delay(1000); 
  
  digitalWrite(LED_PIN, LOW);       
  delay(1000);                       
}
