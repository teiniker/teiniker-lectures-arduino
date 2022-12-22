# Arduino.h

The `Arduino.h` is the main include file for the Arduino SDK.

When we **compile a sketch** in the Arduino IDE, there is certain amount of reorganization taking place to
**convert our sketch into something resembling a proper C/C++ program**.

The header file `Arduino.h` is included at the top of the converted source code.
It is in this file that much of the initialization of a sketch takes place.

## Header Files

Various **standard C/C++ header files** are included.

```C
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
```

A number of **AVR-specific header files** are included from the AVRLib sources.

```C
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
```

Finally, **Arduino specific header files** are included as well.

```C
#include "binary.h"
#include "pins_arduino.h"
```

## Constants
```C
#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352
```

### Macros

```C
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))
```


```C
#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))
#define bit(b) (1UL << (b))
```

### Type Definitions

```C
typedef unsigned int word;
typedef bool boolean;
typedef uint8_t byte;
```

### Function Declarations

```C
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);

unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);
void detachInterrupt(uint8_t interruptNum);

void setup(void);
void loop(void);
```


```C
long random(long);
long random(long, long);
void randomSeed(unsigned long);
long map(long, long, long, long, long);
```

## References
* [GitHub: ArduinoCore-avr/cores/arduino/Arduino.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h)

* Norman Dunbar. **Arduino Software Internals**. APress 2020
    * Chapter 2: Arduino Compilation


*Egon Teiniker, 2020 - 2022, GPL v3.0*     