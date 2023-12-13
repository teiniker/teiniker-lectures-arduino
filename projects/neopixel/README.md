# LED NeoPixel

The WS2812 Integrated Light Source (or NeoPixel) is the
latest advance in the quest for a simple, scalable and affordable full-color LED. Red,
green and blue LEDs are integrated alongside a driver chip into a tiny surface-mount
package controlled through a single wire. They can be used individually, chained into
longer strings or assembled into still more interesting form-factors.


Best Practices
* Before connecting NeoPixels to any large power source, add a capacitor 
(500–1000 µF at 6.3V or higher) across the Vcc and GND terminals. 
The capacitor buffers sudden changes in the current drawn by the strip.

* Place a 300 to 500 Ohm resistor between the Arduino data output pin and the
input to the first NeoPixel. The resistor should be at the end of the wire closest
to the NeoPixel(s), not the microcontroller. Some products already incorporate
this resistor…if you’re not sure, add one…there’s no harm in doubling up! Also,
newer NeoPixels are less picky about this. Nothing’s needed at the “out” end of
a strip…you can leave the data out “floating.”

* Try to minimize the distance between the Arduino and first pixel, so the signal is
clear. A meter or two is usually no problem. Much longer and things can become
unreliable. Individual NeoPixels can act as repeaters for long runs.

* Avoid connecting NeoPixels to a live circuit. If you simply must, always connect
ground first, then +5V, then data. Disconnect in the reverse order

* Each individual NeoPixel draws up to 60 milliamps at maximum brightness white (red
+ green + blue).

* If powering the pixels with a separate supply, apply power to the pixels before
applying power to the microcontroller. Otherwise they’ll try to power
“parasitically” through the data line, which could spell trouble for the
microcontroller.

* If your microcontroller and NeoPixels are powered from two different sources
(e.g. separate batteries for each), there must be a ground connection between
the two.

* NeoPixels powered by 5v ideally need a 5V data signal. If using a 3.3V
microcontroller you must use a logic level shifter such as a 74AHCT125 () or 74H
CT245.
If you are powering your NeoPixels with 3.7v directly from a LiPoly cell, a
3.3v data signal is OK.


## Library Operations

We have to install the [**Adafruit_NeoPixel library**](https://github.com/adafruit/Adafruit_NeoPixel/archive/master.zip) to use the `Adafruit_NeoPixel.h` header file.



* **Adafruit_NeoPixel(uint16_t n, int16_t pin = 6, neoPixelType type = NEO_GRB + NEO_KHZ800)**\
    NeoPixel constructor when length, pin and pixel type are known at compile-time.
    * n: Number of NeoPixels in strand.
    * p: Arduino pin number which will drive the NeoPixel data in.
    * t: Pixel type – add together NEO_* constants defined in Adafruit_NeoPixel.h, for example NEO_GRB+NEO_KHZ800 for NeoPixels expecting an 800 KHz (vs 400 KHz) data stream with color bytes expressed in green, red, blue order per pixel.

    Returns an Adafruit_NeoPixel object.

* **void begin(void)**\
 	Configure NeoPixel pin for output.

* **void setPin(int16_t p)**\
    Set/change the NeoPixel output pin number. Previous pin, if any, is set to INPUT and the new pin is set to OUTPUT.
    * p: Arduino pin number (-1 = no pin).

* **void show(void)**\
    Transmit pixel data in RAM to NeoPixels.


* **void setBrightness(uint8_t b)**\
    Adjust output brightness. Does not immediately affect what's currently displayed on the LEDs. The next call to show() will refresh the LEDs at this level.
    * b: Brightness setting, 0=minimum (off), 255=brightest.

* **uint8_t getBrightness(void) const**\
    Retrieve the last-set brightness value for the strip.

* **void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b)**\
    Set a pixel's color using separate red, green and blue components. 
    * n: Pixel index, starting from 0.
    * r: Red brightness, 0 = minimum (off), 255 = maximum.
    * g: Green brightness, 0 = minimum (off), 255 = maximum.
    * b: Blue brightness, 0 = minimum (off), 255 = maximum.


* **void setPixelColor(uint16_t n, uint32_t c)**\	
    Set a pixel's color using a 32-bit 'packed' RGB or RGBW value.
    * n: Pixel index, starting from 0.
    * c: 32-bit color value. Most significant byte is white (for RGBW pixels) or ignored (for RGB pixels), next is red, then green, and least significant byte is blue.

* **uint32_t getPixelColor(uint16_t n) const**\
    Query the color of a previously-set pixel.
    Returns 'packed' 32-bit RGB value. Most significant byte is 0, next is red, then green, and least significant byte is blue.

* **void fill(uint32_t c = 0, uint16_t first = 0, uint16_t count = 0)**\
    Fill all or part of the NeoPixel strip with a color.
    * c: 32-bit color value. Most significant byte is white (for RGBW pixels) or ignored (for RGB pixels), next is red, then green, and least significant byte is blue. If all arguments are unspecified, this will be 0 (off).
    * first: Index of first pixel to fill, starting from 0. Must be in-bounds, no clipping is performed. 0 if unspecified.
    * count: Number of pixels to fill, as a positive value. Passing 0 or leaving unspecified will fill to end of strip.    

* **void clear(void)**\
 	Fill the whole NeoPixel strip with 0 (black).

There are also **static helper methods**:
* **static uint32_t Color(uint8_t r, uint8_t g, uint8_t b)**\
    Convert separate red, green and blue values into a single "packed" 32-bit RGB color.
    * r: Red brightness, 0 to 255.
    * g: Green brightness, 0 to 255.
    * b: Blue brightness, 0 to 255.


## References

* [Adafruit_NeoPixel Class Reference](https://adafruit.github.io/Adafruit_NeoPixel/html/class_adafruit___neo_pixel.html)

* []()