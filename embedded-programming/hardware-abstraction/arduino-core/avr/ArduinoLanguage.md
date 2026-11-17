# Arduino Language

Arduino language refers to the Arduino specific features of the C/C++
language which relate to the AVR microcontroller and how it operates.
There is no separate compiler: the "language" is a collection of
**macros, constants and functions** provided by the Arduino core
(`cores/arduino/`) and made available by including `Arduino.h`.

The descriptions below refer to the Arduino Uno (ATmega328P, 16 MHz).


## Constants

The most important constants are simple macros defined in `Arduino.h`:

```C++
#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3
```

Because these are plain integers, the compiler cannot detect a wrong
argument: `pinMode(13, HIGH)` compiles without a warning and has the
same effect as `pinMode(13, OUTPUT)`.


## Bit Manipulation

The following bit manipulation macros are defined in the `Arduino.h`
header file.

```C++
#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) \
    ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

#define bit(b) (1UL << (b))
```

* **bit(b)**\
    This macro returns the value of `2^b` where `b` is the bit number
    (0 to 31) as an `unsigned long`.

    _Example_: `bit(5)` returns `2^5 = 32`

* **bitClear(value, bit)**\
    This macro clears the requested `bit`, in the `value` passed, to zero
    and returns the resulting new value.

* **bitRead(value, bit)**\
    This macro returns a one or a zero depending on the state of the `bit`
    requested in the `value` passed.

* **bitSet(value, bit)**\
    This macro can be called to set a specific `bit` in a variable or
    `value` to a one.

* **bitToggle(value, bit)**\
    This macro inverts the requested `bit` in the variable `value`.

* **bitWrite(value, bit, bitvalue)**\
    The purpose of this macro is to call either `bitSet()` or
    `bitClear()` for the appropriate `bit`, in a `value` or variable,
    depending on whether it is to be set to a one or a zero.

* **highByte(w)**\
    This macro returns the value in the higher 8 bits of a 16-bit value
    or variable. It returns a `uint8_t` which is guaranteed to be an
    unsigned, 8-bit value.

* **lowByte(w)**\
    This macro returns the value in the lower 8 bits of a value or
    variable. It returns a `uint8_t` which is guaranteed to be an
    unsigned, 8-bit value.

Note that `bitSet()`, `bitClear()`, `bitToggle()` and `bitWrite()` use
the assignment operator, so the first argument must be a **variable**
(an lvalue), not a constant.

_Example_: Bit manipulation macros

```C++
uint8_t flags = 0b00000000;

bitSet(flags, 3);               // flags = 0b00001000
bitWrite(flags, 0, 1);          // flags = 0b00001001
bitToggle(flags, 3);            // flags = 0b00000001
uint8_t b = bitRead(flags, 0);  // b = 1

uint16_t adc = 0x03FF;
uint8_t hi = highByte(adc);     // hi = 0x03
uint8_t lo = lowByte(adc);      // lo = 0xFF
```

The following macros are defined in the `wiring_private.h` header file.
This file is part of the core and is not included by `Arduino.h`.

```C++
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
```

* **cbi(sfr, bit)**\
    The macro clears the requested bit, in the **register**, to zero.
    We cannot call this macro with a value or variable, it must be a
    special function register (SFR), as defined in the `iom328p.h` file
    which is included indirectly by `Arduino.h`.

* **sbi(sfr, bit)**\
    The macro sets the requested bit in the **register** to one.

_Example_: Start an ADC conversion (`wiring_analog.c`)

```C++
sbi(ADCSRA, ADSC);
```

The names `cbi` and `sbi` come from the AVR instructions **CBI** (clear
bit in I/O register) and **SBI** (set bit in I/O register). For
registers in the lower I/O address space, the compiler translates these
macros into exactly one of these instructions.


## Math

Some mathematical functions are also defined as macros in `Arduino.h`:

```C++
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) \
    ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define sq(x) ((x)*(x))
```

Because these are macros and not functions, an argument can be
**evaluated more than once**. Never pass expressions with side effects:

```C++
int i = 5;
int a = sq(i++);    // expands to ((i++)*(i++)), undefined behavior
int b = sq(i);      // OK
i++;
```

* **long map(long value, long fromLow, long fromHigh, long toLow,
    long toHigh)**\
    Maps a number from one range to another using integer arithmetic.
    The result is **not** limited to the target range, use
    `constrain()` for that.

    _Example_: `map(analogRead(A0), 0, 1023, 0, 255)` scales a 10-bit
    ADC value to an 8-bit PWM value.

* **long random(long max)**\
  **long random(long min, long max)**\
    Returns a pseudo random number between `min` (inclusive, default 0)
    and `max` (exclusive).

* **void randomSeed(unsigned long seed)**\
    Initializes the pseudo random number generator. A common trick is
    `randomSeed(analogRead(A0))` with an unconnected analog pin.


## Digital I/O

The digital pins of the Uno are numbered 0 to 19 (A0 to A5 are the pins
14 to 19). Internally, each pin number is mapped to a **port** (B, C or
D) and a **bit mask** using tables stored in the flash memory
(`variants/standard/pins_arduino.h`).

* **void pinMode(uint8_t pin, uint8_t mode)**\
    The `pinMode()` function sets the direction of a specific pin so that
    it can be used for input or output. The three possible modes are:
    * `INPUT`: The pin state is determined by the voltage applied to it.
        The pin's state is read using `digitalRead()` and will result in
        a returned value `HIGH` or `LOW`.
    * `INPUT_PULLUP`: Input with the internal pullup resistor enabled.
        The default state is pulled to `HIGH` when nothing else attached
        to the pin is attempting to pull it `LOW`.
    * `OUTPUT`: The pin state is set to `HIGH` or `LOW` by a call to
        `digitalWrite()`.

    Internally, `pinMode()` writes to the data direction register `DDRx`
    (and to `PORTx` for the pullup resistor).

* **void digitalWrite(uint8_t pin, uint8_t val)**\
    Sets an output pin to `HIGH` (5V) or `LOW` (0V). Any value other
    than `LOW` is treated as `HIGH`.
    If the pin is configured as `INPUT`, `digitalWrite(pin, HIGH)`
    enables the internal pullup resistor.

* **int digitalRead(uint8_t pin)**\
    Reads the value of a digital pin and returns either `HIGH` or `LOW`.
    An unconnected input pin is "floating" and returns random values,
    so use `INPUT_PULLUP` or an external resistor.

_Example_: Implementation of `digitalWrite()` (`wiring_digital.c`)

```C++
void digitalWrite(uint8_t pin, uint8_t val)
{
    uint8_t timer = digitalPinToTimer(pin);
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t *out;

    if (port == NOT_A_PIN) return;

    // If the pin that support PWM output, we need to turn it off
    // before doing a digital write.
    if (timer != NOT_ON_TIMER) turnOffPWM(timer);

    out = portOutputRegister(port);

    uint8_t oldSREG = SREG;
    cli();

    if (val == LOW) {
        *out &= ~bit;
    } else {
        *out |= bit;
    }

    SREG = oldSREG;
}
```

The implementation shows the price of the abstraction:

* The pin number is translated into a port register and a bit mask at
    **runtime** by reading tables from the flash memory.

* A PWM output on this pin is switched off.

* Interrupts are disabled while the port register is modified, because
    the read-modify-write sequence (`*out |= bit`) is not atomic.

A direct register access like `PORTB |= (1 << PB5);` is therefore
much faster (one `SBI` instruction) than `digitalWrite(13, HIGH);`, but
it is not portable between different boards.


## Analog I/O

* **int analogRead(uint8_t pin)**\
    Reads the voltage at an analog input pin (`A0` to `A5`) using the
    built-in **10-bit analog to digital converter** (ADC). The result is
    a value between 0 and 1023:

    ```
    value = Vin * 1024 / Vref
    ```

    With the default reference of 5V, the resolution is about 4.9 mV.
    A conversion takes about 100 microseconds (ADC clock 125 kHz, 13 ADC
    clock cycles), and `analogRead()` waits until it is finished.
    Both channel numbers (0 to 5) and pin numbers (`A0` = 14 to
    `A5` = 19) are accepted.

* **void analogReference(uint8_t mode)**\
    Selects the reference voltage `Vref` used by the ADC:
    * `DEFAULT`: supply voltage (5V on the Uno)
    * `INTERNAL`: internal 1.1V reference
    * `EXTERNAL`: voltage applied to the AREF pin (0 to 5V only!)

* **void analogWrite(uint8_t pin, int val)**\
    Despite its name, `analogWrite()` does not output an analog voltage.
    It generates a **PWM** (pulse width modulation) signal with a
    **duty cycle** of `val / 255`:
    * `analogWrite(pin, 0)`: always `LOW`
    * `analogWrite(pin, 127)`: about 50% `HIGH`
    * `analogWrite(pin, 255)`: always `HIGH`

    The function calls `pinMode(pin, OUTPUT)` itself. PWM is only
    available on pins connected to a timer output:

    | Pins     | Timer  | PWM frequency |
    |:--       |:--     |--:            |
    | 5, 6     | Timer0 | 976.6 Hz      |
    | 9, 10    | Timer1 | 490.2 Hz      |
    | 3, 11    | Timer2 | 490.2 Hz      |

    All timers use a prescaler of 64. Timer0 runs in fast PWM mode
    (`16 MHz / 64 / 256`), Timer1 and Timer2 in phase correct PWM mode
    (`16 MHz / 64 / 510`). On other pins, values below 128 result in
    `LOW` and values from 128 result in `HIGH`.


## Advanced I/O

* **void tone(uint8_t pin, unsigned int frequency,
    unsigned long duration = 0)**\
    Generates a square wave with 50% duty cycle and the given
    `frequency` (in Hz) on any pin. If `duration` (in milliseconds) is 0,
    the tone plays until `noTone()` is called.
    `tone()` uses **Timer2**, therefore PWM on the pins 3 and 11 does not
    work while a tone is playing. Only one tone can be generated at a
    time.

* **void noTone(uint8_t pin)**\
    Stops the square wave started by `tone()`.

* **void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder,
    uint8_t val)**\
    Shifts out a byte one bit at a time (software SPI). For each bit, the
    data pin is set and a clock pulse is generated. `bitOrder` is
    either `MSBFIRST` or `LSBFIRST`. Typically used with shift registers
    like the 74HC595.

* **uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin,
    uint8_t bitOrder)**\
    Shifts in a byte one bit at a time, e.g. from a 74HC165 shift
    register.

* **unsigned long pulseIn(uint8_t pin, uint8_t state,
    unsigned long timeout = 1000000L)**\
    Reads a pulse (either `HIGH` or `LOW`) on a pin.
    For example, if `state` is `HIGH`, `pulseIn()` waits for the `pin`
    to go from `LOW` to `HIGH`, starts timing, then waits for the pin to
    go `LOW` and stops timing.

    `timeout` specifies the number of microseconds to wait for the pulse
    to start, the default is one second.

    Returns the **length of the pulse in microseconds** or gives up and
    returns 0 if no complete pulse was received within the timeout.

    The timing of this function has been determined empirically and
    will probably show errors in longer pulses. Works on pulses from 10
    microseconds to 3 minutes in length.

    _Example_: Measure the echo pulse of an HC-SR04 ultrasonic sensor

    ```C++
    unsigned long duration = pulseIn(PIN_ECHO, HIGH);
    float distance_cm = duration * 0.0343 / 2;
    ```

* **unsigned long pulseInLong(uint8_t pin, uint8_t state,
    unsigned long timeout = 1000000L)**\
    Alternative to `pulseIn()` which uses `micros()` for the time
    measurement. It is better suited for long pulses, but only works if
    interrupts are enabled.


## Time

The Arduino core configures **Timer0** in `init()` (`wiring.c`), which
is called before `setup()`. With a prescaler of 64, Timer0 overflows
every `64 * 256 / 16 MHz = 1024` microseconds. The interrupt service
routine `ISR(TIMER0_OVF_vect)` updates a millisecond counter.

* **unsigned long millis(void)**\
    Returns the number of milliseconds since the program started. The
    value overflows (goes back to zero) after about **49.7 days**
    (`2^32` ms).

* **unsigned long micros(void)**\
    Returns the number of microseconds since the program started. On a
    16 MHz board the resolution is **4 microseconds**. The value
    overflows after about **70 minutes**.

* **void delay(unsigned long ms)**\
    Pauses the program for the given number of milliseconds. During this
    time the CPU is busy waiting and cannot do anything else (except
    executing interrupt service routines).

* **void delayMicroseconds(unsigned int us)**\
    Pauses the program for the given number of microseconds. It is
    implemented as a busy loop that counts CPU cycles and does not use
    Timer0. The largest value that produces an accurate delay is 16383.

Because `delay()` blocks the program, it is better to use `millis()` for
tasks that run periodically. The subtraction of `unsigned long` values
also works correctly when `millis()` overflows:

_Example_: Non blocking blink

```C++
const unsigned long INTERVAL = 500;
unsigned long previous = 0;

void loop()
{
    unsigned long now = millis();
    if(now - previous >= INTERVAL)
    {
        previous = now;
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
    // other tasks ...
}
```


## Interrupts

* **void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void),
    int mode)**\
    Registers the function `userFunc` as interrupt service routine for an
    **external interrupt**. The Uno has two external interrupts: `INT0`
    on pin 2 and `INT1` on pin 3. The `mode` defines when the interrupt
    is triggered:
    * `LOW`: as long as the pin is `LOW`
    * `CHANGE`: whenever the pin changes its value
    * `RISING`: when the pin goes from `LOW` to `HIGH`
    * `FALLING`: when the pin goes from `HIGH` to `LOW`

* **void detachInterrupt(uint8_t interruptNum)**\
    Turns off the given interrupt.

* **digitalPinToInterrupt(pin)**\
    A macro which translates a pin number into an interrupt number. For
    pins without external interrupt it returns `NOT_AN_INTERRUPT` (-1).

    ```C++
    #define digitalPinToInterrupt(p) \
        ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))
    ```

    Always use this macro instead of the interrupt number, because the
    mapping differs between boards.

* **interrupts()**\
  **noInterrupts()**\
    Macros which enable or disable all interrupts globally. They are
    mapped to the AVR instructions `sei` (set global interrupt flag) and
    `cli` (clear global interrupt flag).

    ```C++
    #define interrupts() sei()
    #define noInterrupts() cli()
    ```

_Example_: Count button presses with an interrupt

```C++
const uint8_t PIN_BUTTON = 2;

volatile unsigned long counter = 0;

void on_button()        // interrupt service routine
{
    counter++;
}

void setup()
{
    Serial.begin(9600);
    pinMode(PIN_BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), on_button, FALLING);
}

void loop()
{
    noInterrupts();
    unsigned long value = counter;  // read 32-bit value atomically
    interrupts();

    Serial.println(value);
    delay(1000);
}
```

Rules for interrupt service routines:

* Keep the function **short and fast**.

* Variables shared between the ISR and the main program must be declared
    `volatile`, otherwise the compiler may keep the value in a register.

* Reading a multi-byte variable is not atomic on an 8-bit CPU. Disable
    interrupts while copying it, as shown in `loop()` above.

* Inside an ISR, interrupts are disabled. `delay()` does not work and
    `millis()` does not increment. `Serial.print()` should be avoided.


## References

* [GitHub: ArduinoCore-avr/cores/arduino/](https://github.com/arduino/ArduinoCore-avr/tree/master/cores/arduino)

* [Arduino Language Reference](https://docs.arduino.cc/language-reference/)

* Norman Dunbar. **Arduino Software Internals**. APress 2020
    * Chapter 3: Arduino Language Reference

*Egon Teiniker, 2020-2026, GPL v3.0*
