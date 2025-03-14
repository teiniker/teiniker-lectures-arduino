#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to
#define NUMPIXELS 24 // number of neopixels in strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{  
  pixels.begin();	// Initialize the NeoPixel library.
}

void loop() {
  static int posRed = 0;               // Initial position for the red pixel
  static int posGreen = NUMPIXELS - 1; // Initial position for the green pixel

  pixels.clear(); // Clear all pixels to black before setting new ones

  // Set Red pixel
  pixels.setPixelColor(posRed, pixels.Color(255, 0, 0));

  // Set Green pixel
  pixels.setPixelColor(posGreen, pixels.Color(0, 255, 0));

  pixels.show(); // Update the strip with new data
  delay(100);    // Delay for smooth animation (adjust as needed)

  // Move positions for the next iteration
  posRed = (posRed + 1) % NUMPIXELS;                   // Increment red position
  posGreen = (posGreen - 1 + NUMPIXELS) % NUMPIXELS;   // Decrement green position (wrap around)
}