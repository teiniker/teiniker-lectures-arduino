# Timing: delay() vs. millis() 

Running the following examples, we can use a simple circuit of two LEDs.

![Arduino Uno Board](figures/TwoLEDs.png)


## delay() Function

We can use the function `delay()` to force arduino to wait a given time interval.
* **void delay(unsigned long)**\
  Pauses the program for the amount of time (in milliseconds) specified as parameter.

For example, we can use `delay()` to to make an LED blink:
```C
void loop() 
{
  digitalWrite(LED_PIN, HIGH);
  delay(500);                       
  
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
```

The disadvantage of `delay()` is that it is a **blocking function**.
Blocking functions prevent a program from doing anything else until that particular task has completed.
However, it is very often necessary to execute another task during the waiting time.

_Example:_ [TinkerCAD: Blink delay()](https://www.tinkercad.com/things/7TIAkPiA0M0)


## millis() Function

These restrictions can be avoided with the `millis()` function which is a **non-blocking operation**.
Instead of waiting for a certain time, we can always check whether a certain time has already passed.

* **unsigned long millis()**\
  Returns the number of milliseconds passed since the Arduino board began running the current program. 
  This number will overflow (go back to zero), after approximately 50 days.

```C
void loop() 
{
  if(millis() >= timestamp + INTERVAL)
  {
      timestamp = millis();
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
```
Whenever the value of `millis()` is as large as the last timestamp plus the desired interval, 
the status of the LED is changed and the current value of `millis()` is saved as a timestamp.

_Example:_ [TinkerCAD: Blink millis()](https://www.tinkercad.com/things/gsCB4b6UFDm)


## References 
* [Blink Without Delay](https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay)
* [Using millis() for timing](https://learn.adafruit.com/multi-tasking-the-arduino-part-1/using-millis-for-timing)
* [Arduino Tutorial: Using millis() Instead of delay()](https://www.norwegiancreations.com/2017/09/arduino-tutorial-using-millis-instead-of-delay/)

*Egon Teiniker, 2020-2025, GPL v3.0* 

