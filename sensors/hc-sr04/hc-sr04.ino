#include "SR04.h"

const int TRIG_PIN = 9;
const int ECHO_PIN = 8; 

SR04 sensor = SR04(ECHO_PIN,TRIG_PIN);
long distance;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
   distance = sensor.Distance();
   Serial.print(distance);
   Serial.println("cm");    
   delay(250); 
}
