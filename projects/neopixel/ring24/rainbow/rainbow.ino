#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to
#define NUMPIXELS 24 // number of neopixels in strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{  
  pixels.begin();	// Initialize the NeoPixel library.
}

void loop() {
  static int currentPixel = 0; // Current pixel position

  // Calculate rainbow color for current pixel
  int hue = map(currentPixel, 0, NUMPIXELS, 0, 65535);
  uint32_t color = pixels.gamma32(pixels.ColorHSV(hue));

  pixels.setPixelColor(currentPixel, color);
  pixels.show(); // Display the current pixel
  delay(100);    // Control the animation speed

  currentPixel++;

  // After completing the cycle, clear and start again
  if (currentPixel >= NUMPIXELS) {
    delay(500);        // Small pause before clearing
    pixels.clear();    // Turn off all LEDs
    pixels.show();
    currentPixel = 0;  // Reset position
  }
}