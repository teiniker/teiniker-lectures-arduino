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

We use a simple LED to output a state that is changed in every timer interval.

![Timer 1 Blink](figures/Arduino-Digital-Output.png)



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

When programming an Interrupt Service Routine (ISR):

* **Keep it short and fast**: 
    While the ISR is running, other interrupts (like millis() incrementing 
    or Serial data arrival) are blocked.
    - Do: Set a flag (a boolean) or update a counter and exit.
    - **Don't**: Perform complex math, use delay(), or execute long for loops.

* **Avoid Serial.print()**: 
    Never use `Serial.print()` inside an ISR. Serial communication relies 
    on interrupts to send data. If we call it inside an ISR where interrupts 
    are disabled, our code will likely hang or behave unpredictably.

* **Use the volatile Keyword**:
    Any variable that is shared between your ISR and your main `loop()` 
    must be declared as `volatile`. This tells the compiler that the value 
    can change at any moment, preventing it from incorrectly caching the 
    value in a CPU register.

* **Atomic Access for Multi-byte Variables**:
    The Arduino Uno is an 8-bit microcontroller. This means it can only read 
    one byte at a time. If you are sharing a 16-bit or 32-bit variable 
    between the ISR and the main loop, an interrupt could trigger while the 
    main loop is halfway through reading the variable.


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