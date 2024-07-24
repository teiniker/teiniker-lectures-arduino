#include <Adafruit_NeoPixel.h>

void setup() 
{  
}

void loop() 
{ 
   rotate(8, 1);
   rotate(7, 8);
   rotate(6, 12);
   rotate(5, 16);
   rotate(4, 20);
   rotate(3, 24);
   rotate(2, 28);
 
}

void rotate(int pin, int num_pixels)
{
    delay(500);
    Adafruit_NeoPixel pixels = Adafruit_NeoPixel(num_pixels, pin, NEO_GRB + NEO_KHZ800);
    pixels.begin();	// Initialize the NeoPixel library.
    pixels.setBrightness(40);


    for (int i=0; i < num_pixels; i++) 
    {
      pixels.setPixelColor(i, pixels.Color(0xff, 0xff, 0xff));
      pixels.show();
      delay(50);	  
    }
   
    for (int i=0; i < num_pixels; i++) 
    {
      pixels.setPixelColor(i, 0x000000);
      pixels.show();
      delay(50);	  
    }
}