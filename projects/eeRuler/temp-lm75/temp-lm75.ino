#include <Wire.h>
#include "LM75.h"

LM75 sensor; 

void setup() 
{
  Serial.begin(115200);
  Wire.begin();
}

void loop() 
{
  float temp = sensor.temp();
  Serial.println(temp);
  delay(500);
}
