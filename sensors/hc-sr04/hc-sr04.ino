#include <SR04.h>

const int TRIG_PIN = 9;
const int ECHO_PIN = 8; 

SR04 sr04(ECHO_PIN,TRIG_PIN);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
   long distances = sr04.Distance();
   Serial.print(distances);
   Serial.println(" cm");    
   delay(250); 
}
