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
  static int hueOffset = 0;   // Anfangswert für den Farbverlauf
  static int brightness = 45;  // Helligkeit (0-255)
  static int dimDirection = 1; // Richtung des Dimmens (1 heller, -1 dunkler)

  for(int i = 0; i < NUMPIXELS; i++) {
    int pixelHue = hueOffset + (65536 / NUMPIXELS) * i;
    pixels.setPixelColor(i, pixels.ColorHSV(pixelHue, 255, brightness));
  }

  pixels.show();
  delay(30);  // Verzögerung für die Geschwindigkeit des Regenbogens und des Dimmens

  hueOffset += 256;  // Farbwert erhöhen für Animation
  hueOffset %= 65536;  // Zurücksetzen des Farbwertes für kontinuierliche Animation

  brightness += dimDirection;
  if(brightness >= 255 || brightness <= 0) {
    dimDirection *= -1;  // Richtung des Dimmens umkehren
  }
}