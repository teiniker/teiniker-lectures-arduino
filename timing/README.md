# Timing Without delay()

The delay() function has the disadvantage that no other activities can be carried out during this time.
However, it is very often necessary to execute another task during the waiting time.

These restrictions can be avoided with the millis() function.
Instead of waiting for a certain time, you can always check whether a certain time has already passed.

* **unsigned long millis()**
  Returns the number of milliseconds passed since the Arduino board began running the current program. This number will overflow (go back to zero), after approximately 50 days.

## References 
* [Blink Without Delay](https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay)
* [Using millis() for timing](https://learn.adafruit.com/multi-tasking-the-arduino-part-1/using-millis-for-timing)

*Egon Teiniker, 2020 - 2021, GPL v3.0* 