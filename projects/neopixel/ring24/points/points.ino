#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to
#define NUMPIXELS 24 // number of neopixels in strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{  
  pixels.begin();	// Initialize the NeoPixel library.
}

void loop() 
{
  static int currentPixel = 0;      // Current pixel position
  static int hue = 0;               // Current color hue

  pixels.setPixelColor(currentPixel, pixels.ColorHSV(hue));
  pixels.show();

  delay(50);                        // Adjust delay for speed of rainbow transition

  currentPixel++;
  hue += 65536 / NUMPIXELS;         // Increment hue for rainbow steps

  if (currentPixel >= NUMPIXELS) {
    delay(500);                     // Pause briefly after completing one rainbow cycle
    pixels.clear();                 // Clear all pixels
    pixels.show();
    currentPixel = 0;               // Reset pixel counter
    hue = 0;                        // Reset hue to start the rainbow again
  }
}