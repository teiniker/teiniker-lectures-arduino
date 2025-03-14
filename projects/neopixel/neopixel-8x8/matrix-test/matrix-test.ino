#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to

#define NUMPIXELS 64 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{  
  pixels.begin();	// Initialize the NeoPixel library.
}


void loop() 
{
  pixels.setBrightness(40);
  
  for (int i=0; i < NUMPIXELS; i++) 
  {
    pixels.setPixelColor(i, pixels.Color(0x00, 0xff, 0x00));
    pixels.show();
    delay(50);	  
  }
   
  for (int i=0; i < NUMPIXELS; i++) 
  {
    pixels.setPixelColor(i, 0x000000);
    pixels.show();
    delay(50);	  
  }
}
