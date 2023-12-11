#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to

#define NUMPIXELS 24 // number of neopixels in strip

Adafruit_NeoPixel pixels = 
  Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{  
  pixels.begin();	// Initialize the NeoPixel library.
}

void loop() { 
  int redPixel = 0;         // Start the red pixel at position 0
  int greenPixel = NUMPIXELS - 1; // Start the green pixel at the opposite end

  while(true) {  // Infinite loop
    pixels.clear();  // Turn all pixels off

    // Set the red and green pixels
    pixels.setPixelColor(redPixel, pixels.Color(255,0,0)); // Red color
    pixels.setPixelColor(greenPixel, pixels.Color(0,255,0)); // Green color
    pixels.show();   // Apply the changes

    // Move the red pixel forward, and the green pixel backward
    redPixel = (redPixel + 1) % NUMPIXELS;
    greenPixel = (greenPixel - 1 + NUMPIXELS) % NUMPIXELS;

    delay(100); // Delay for a moment to see the change
  }
}
