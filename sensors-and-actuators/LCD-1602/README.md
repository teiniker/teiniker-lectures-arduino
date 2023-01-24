# LCD Display Module

**Liquid Crystal Displays** or LCDs have been used in electronics equipment since the late 1970s.   LCD displays have the advantage of consuming very little current.

LCD displays do not emit light. Instead they block the passage of light, like little windows which open and shut the let light through. The liquid crystals used inside LCD displays are sandwiched between two layers of polarized material. By changing the orientation of the liquid crystals they allow light to pass or they block the light entirely.


## Wiring Diagram

Because the LCD module uses a parallel data input it requires 8 connections to the host microcontroller for the data alone. Add that to the other control pins and it consumes a lot of connections.  On an Arduino Uno half of the I/O pins would be taken up by the display, which can be problematic if you want to use the I/O pins for other input or output devices.

One way of reducing the number of connections required is to use **4-wire mode**, and most projects that make use of this display do exactly that.

In 4-wire mode the data is sent a half a byte at a time, thus requiring only 4 data connections. The upper half of the data input (D4 to D7) is used while the other pins are not connected to anything.

![LCD](figures/LCD.png)


## Source Code

```C
#include <LiquidCrystal.h>

// LCD wiring
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4; 
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() 
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
```


## Simulation

Via **Tinkercad** we can simulate the following examples: 
* [Arduino: LCD using print()](https://www.tinkercad.com/things/8h7D4nFDaNc) 
* [Arduino: LCD creating custom characters](https://www.tinkercad.com/things/6uqhYRkPX45)

Note that all examples share the same wiring.

## Library Operations

The library based on `LiquidCrystal.h` allows an Arduino board to control Liquid Crystal Displays (LCDs) based on the **Hitachi HD44780** chipset, which is found on most text-based LCDs. The library works with in either **4- or 8-bit mode**.

* **LiquidCrystal(rs, enable, d4, d5, d6, d7)**\
  **LiquidCrystal(rs, rw, enable, d4, d5, d6, d7)**\
  **LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7)**\
  **LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)**\
  Creates a variable of type LiquidCrystal. The display can be controlled using 4 or 8 data lines.
  * `rs`: The number of the Arduino pin that is connected to the RS pin on the LCD
  * `rw`: The number of the Arduino pin that is connected to the RW pin on the LCD (optional)
  * `enable`: The number of the Arduino pin that is connected to the enable pin on the LCD
  * `d0`, `d1`, `d2`, `d3`, `d4`, `d5`, `d6`, `d7`: The numbers of the Arduino pins that are connected to the corresponding data pins on the LCD.
    `d0`, `d1`, `d2`, and `d3` are optional; if omitted, the LCD will be controlled using only the four data lines (`d4`, `d5`, `d6`, `d7`).
  
* **void begin(uint8_t cols, uint8_t rows)**\
  Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display. 
  `begin()` needs to be called before any other LCD library commands.
  * `cols`: The number of columns that the display has
  * `rows`: The number of rows that the display has  
  
* **void clear()**\
  Clears the LCD screen and positions the cursor in the upper-left corner.

* **void home()**\
  Positions the cursor in the upper-left of the LCD. That is, use that location in outputting subsequent text to the display. To also clear the display, use the `clear()` function instead.
  
* **void setCursor(uint8_t col, uint8_t row)**\
  Position the LCD cursor; that is, set the location at which subsequent text written to the LCD will be displayed.
  * `col`: the column at which to position the cursor (with 0 being the first column)
  * `row`: the row at which to position the cursor (with 0 being the first row)
  
* **size_t Serial.print(T value)**\
  **size_t print(T value, int BASE)**\  
  Prints data as text to the LCD. `print()` will return the number of bytes written.
  * `data`: the data to print (`char`, `byte`, `int`, `long`, or `string`)
  * `BASE` (optional): the base in which to print numbers: `BIN` for binary (base 2), `DEC` for decimal (base 10), 
    `OCT` for octal (base 8), `HEX` for hexadecimal (base 16).
    
* **void noDisplay()**\
 Turns off the LCD display, without losing the text currently shown on it.
 
* **void display()**\
  Turns on the LCD display, after it’s been turned off with `noDisplay()`. This will restore the text (and cursor) that was on the display.
  
* **void noCursor()**\
  Hides the LCD cursor.
 
* **void cursor()**\
  Display the LCD cursor: an underscore (line) at the position to which the next character will be written.
   
* **void noBlink()**\
  Turns off the blinking LCD cursor.
 
* **void blink()**\
  Display the blinking LCD cursor. If used in combination with the `cursor()` function, the result will depend on the particular display.  
  
* **void leftToRight()**\
  Set the direction for text written to the LCD to left-to-right, the default. 
  This means that subsequent characters written to the display will go from left to right, but does not affect previously-output text.

* **void rightToLeft()**\
  Set the direction for text written to the LCD to right-to-left (the default is left-to-right). 
  This means that subsequent characters written to the display will go from right to left, but does not affect previously-output text.

* **void noAutoscroll()**\
  Turns off automatic scrolling of the LCD.
  
* **void autoscroll()**\
   Turns on automatic scrolling of the LCD. 
   This causes each character output to the display to push previous characters over by one space. 
   If the current text direction is left-to-right (the default), the display scrolls to the left; 
   if the current direction is right-to-left, the display scrolls to the right. 
   This has the effect of outputting each new character to the same location on the LCD.

* **void scrollDisplayLeft()**\
  Scrolls the contents of the display (text and cursor) one space to the left.

* **void scrollDisplayRight()**\
  Scrolls the contents of the display (text and cursor) one space to the right.


* **void createChar(uint8_t num, uint8_t data[])**\
 Create a custom character (glyph) for use on the LCD. Up to eight characters of 5x8 pixels are supported (numbered 0 to 7). 
 The appearance of each custom character is specified by an array of eight bytes, one for each row. 
 The five least significant bits of each byte determine the pixels in that row. To display a custom character on the screen, `write()` its number.
 * `num`: which character to create (0 to 7)
 * `data`: the character’s pixel data
 
* **virtual size_t write(uint8_t num)**\
  Write a character to the LCD.
  Returns the number of bytes written.
  * `data`: The character to write to the display.
    
  
## References

* [YouTube (DroneBot Workshop): Using LCD Displays with Arduino](https://youtu.be/wEbGhYjn4QI)
* [DroneBot Workshop: Using LCD Displays with Arduino](https://dronebotworkshop.com/lcd-displays-arduino/)

* [Liquid Crystal Displays (LCD) with Arduino](https://docs.arduino.cc/learn/electronics/lcd-displays)

* [Arduino Reference: LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/)
* [GitHub: LiquidCrystal Library for Arduino](https://github.com/arduino-libraries/LiquidCrystal)

*Egon Teiniker, 2020 - 2023, GPL v3.0*
