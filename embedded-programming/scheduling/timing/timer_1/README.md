# TimerOne Library

TimerOne is an Arduino library that provides easy, high-level access 
to **Hardware Timer1** on **AVR-based boards such as the Arduino Uno**.

Instead of manually configuring timer registers (which is error-prone 
and hardware-specific), TimerOne lets you:
* Configure precise time intervals
* Attach interrupt service routines (ISRs)
* Generate PWM signals with fine resolution

The Arduino Uno uses the **ATmega328P** microcontroller, which has 
three timers:

* **Timer0 (8-bit)**: Used by `millis()`, `micros()`, `delay()`

* **Timer1 (16-bit)**: Not used by Arduino (used by TimerOne)

* **Timer2 (8-bit)**: Used by `tone()`

TimerOne exclusively controls Timer1, which means:
* It does not interfere with `millis()` or `delay()`
* It does override default PWM behavior on certain pins


## Wiring Diagram


## Source Code

We have to install the **TimerOne** library to use the `TimerOne.h` header file.

```C++
#include <TimerOne.h>

const int ledPin = 2;

// volatile means that this variable can be changed in an interrupt
volatile bool ledState = false;

void ISR_blink_led() 
{
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
}

void setup() 
{
  pinMode(ledPin, OUTPUT);

  // Initialize Timer1 to trigger every 1,000,000 microseconds (1 second)
  Timer1.initialize(1000000); 
  
  // Attach the ISR function to the timer
  Timer1.attachInterrupt(ISR_blink_led); 
}
```

The **volatile** keyword is a type qualifier used to tell the compiler that 
a variable's value can be changed by something outside the control of the 
code currently executing.

Because modern compilers are highly aggressive about optimization, they often 
assume that a variable's value stays the same unless the code explicitly modifies 
it. `volatile` prevents these optimizations.

When we mark a variable as `volatile`, we are giving the compiler two specific 
instructions:

* **No Caching**: The compiler must read the value from the actual memory address 
    every single time it is referenced, rather than reusing a value it previously 
    loaded into a CPU register.

* **No Reordering**: The compiler cannot optimize away or reorder read/write 
    operations involving that variable.


## Library Operations

* **Timer1.initialize(unsigned long microseconds)**: Timer1 initialization
    - Sets the **timer period in microseconds**
    - Automatically selects prescaler and compare value
    - Maximum practical period ≈ 8 seconds

* **Timer1.attachInterrupt(void (*isr)())**: Attaching an Interrupt 
    Service Routine (ISR)
    - Attaches an ISR function
    - ISR runs at the configured interval

* **Timer1.detachInterrupt()**: Detaching an Interrupt
    - Stops the timer interrupt

* **Stop and Resume Timer1**:
    - `Timer1.stop()`
    - `Timer1.start()`
    - `Timer1.restart()`

* **Timer1.pwm(pin, duty)**: PWM Output
    - `pin`: 9 or 10 (hardware PWM pins for Timer1)
    - `duty`: 0–1023 (10-bit resolution)

* **Timer1.setPwmDuty(pin, duty)**: Change Duty Cycle
    - `pin`: 9 or 10 (hardware PWM pins for Timer1)
    - `duty`: 0–1023 (10-bit resolution)
   

## References

* [GitHub: TimerOne Library](https://github.com/PaulStoffregen/TimerOne)

_Egon Teiniker, 2020-2025, GPL v3.0_