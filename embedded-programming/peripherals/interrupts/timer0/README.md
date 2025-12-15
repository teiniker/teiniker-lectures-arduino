# Timer 0 Interrupt

In Arduino, the `millis()` function, which returns the number of
milliseconds since the Arduino board began running the current program, 
is typically implemented using one of the built-in hardware timers of 
the microcontroller. 

For most Arduino boards, including the Arduino Uno which uses 
the **ATmega328P** microcontroller, **millis() is driven by Timer 0**.

Here's how it works:

* **Timer 0 Configuration**: Timer 0 is set up to **increment a counter
    every millisecond**. This is achieved by configuring the timer with 
    a prescaler and, if necessary, a compare match value, depending on 
    the clock frequency of the microcontroller.

* **Interrupt**: In some implementations, the timer is configured to 
    generate an overflow interrupt. In others, a compare match 
    interrupt is used. 
    When this interrupt occurs (either on overflow or on compare match), an interrupt service routine (ISR) is executed.

* **Incrementing the Millisecond Counter**: Inside this ISR, a global
    variable that keeps track of the number of milliseconds is incremented. This variable is what is returned by the `millis()` function.

* **Non-blocking and Asynchronous**: Since this process is 
    interrupt-driven, it operates independently of the main program 
    loop, allowing `millis()` to count up regardless of what the main program is doing, unless interrupts are disabled.


It's important to note that modifying Timer 0 or its interrupts can 
affect the behavior of `millis()`, as well as other functions that 
rely on it, such as `delay()` and `micros()`. 

## References

* [ATmega328p Datasheet](/hardware/microcontroller/atmega328p/)

*Egon Teiniker, 2020-2024, GPL v3.0* 