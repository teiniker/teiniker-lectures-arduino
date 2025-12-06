#include <Wire.h>

void setup() 
{
  Wire.begin(); // join i2c bus (address optional for master)
}


uint8_t invert(uint8_t data)
{
  return data ^ 0xff;
}

void loop() 
{
  uint8_t data = 0x01;
  
  for(uint8_t n = 0; n < 8; n++)
  {
    Wire.beginTransmission(0x20);     // PCF8574 IO (addresses from 0x20 to 0x27)
    Wire.write(invert(data << n));    // send one bytes
    Wire.endTransmission();           // stop transmitting
    delay(500);
  }

  data = 0x80;
  for(uint8_t n = 0; n < 8; n++)
  {
    Wire.beginTransmission(0x20);     // PCF8574 IO (addresses from 0x20 to 0x27)
    Wire.write(invert(data >> n));    // send one bytes
    Wire.endTransmission();           // stop transmitting
    delay(500);
  }  
}
