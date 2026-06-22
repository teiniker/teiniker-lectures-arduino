# OOP in Arduino Libraries

Implementing Arduino libraries as classes offers several key benefits:

* **Encapsulation**: Pin numbers and internal state (e.g. timing counters,
  last readings) are stored as private member variables. The user of the
  library only interacts with a clean public interface and does not need
  to know the internal details.

* **Abstraction**: Complex hardware protocols (e.g. generating a trigger
  pulse and measuring echo time for an ultrasonic sensor) are hidden
  behind simple method calls like `Distance()`. The sketch stays readable
  and focused on application logic.

* **Reusability**: A class can be instantiated multiple times for
  different hardware units (e.g. two buttons, two sensors) without
  duplicating any code.

* **Separation of concerns**: Hardware-specific code lives in the library,
  while the sketch contains only application logic. This makes both parts
  easier to maintain and test independently.


## Practical Examples

### RGB LED

The `RGBLed` class (library `RGB-1.0.10`) controls an RGB LED connected
to three PWM-capable digital pins.

```cpp
class RGBLed
{
public:
    RGBLed(int red, int green, int blue, bool common);

    void off();
    void setColor(int red, int green, int blue);
    void brightness(int red, int green, int blue, int brightness);
    void flash(int red, int green, int blue, int duration);
    void fadeIn(int red, int green, int blue, int steps, int duration);
    void fadeOut(int red, int green, int blue, int steps, int duration);
    void crossFade(...);
    void gradient(...);

    static bool COMMON_ANODE;
    static bool COMMON_CATHODE;
    static int RED[3], GREEN[3], BLUE[3], ...;

private:
    int _red, _green, _blue, _common, _brightness;
    ...
};
```

The constructor takes the three pin numbers and a polarity flag
(`COMMON_ANODE` or `COMMON_CATHODE`). The private members store the
pin assignments and current brightness so that all methods can operate
on them without the caller managing any state.

Predefined static color constants (`RED`, `GREEN`, `BLUE`, `MAGENTA`,
`CYAN`, `YELLOW`, `WHITE`) make sketches more readable.


### Debounce

The `Debounce` class (library `Debounce-1.2`) removes contact bounce
from a push button using a time-based filtering approach.

```cpp
class Debounce
{
public:
    Debounce(byte button,
             unsigned long delay = 50,
             boolean pullup = true);

    byte read();           // returns debounced state: LOW or HIGH
    unsigned int count();  // number of times button was pressed
    void resetCount();     // resets the press counter

private:
    byte _button, _state, _lastState, _reading;
    unsigned int _count;
    unsigned long _delay, _last;
    boolean _wait, _invert;
};
```

The constructor takes the pin number, an optional debounce delay in
milliseconds (default 50 ms), and an optional pull-up flag. All timing
state (`_last`, `_wait`) is stored privately, so multiple `Debounce`
instances for different buttons are fully independent.


### HC-SR04

The `SR04` class (library `HC-SR04`) controls an HC-SR04 ultrasonic
distance sensor.

```cpp
class SR04
{
public:
    SR04(int echoPin, int triggerPin);

    long Distance();
    long DistanceAvg(int wait = DEFAULT_DELAY,
                     int count = DEFAULT_PINGS);
    void Ping();
    long getDistance();

private:
    long MicrosecondsToCentimeter(long duration);

    int _echoPin, _triggerPin;
    long _currentDistance, _duration, _distance;
    bool _autoMode;
};
```

The constructor stores the echo and trigger pin numbers. `Distance()`
sends a 10 us trigger pulse and converts the echo duration to
centimeters using the speed of sound (340 m/s). `DistanceAvg()` takes
multiple readings and averages them, discarding the min and max values
to reduce noise. The conversion formula and pin handling are fully
hidden from the caller.


## References

* [RGB LED Library](../../../sensors-and-actuators/user-interface/rgb-led/)

* [Debounce Library](../../../sensors-and-actuators/user-interface/button-debouncing/)

* [HC-SR04 Ultrasonic Sensor Library](../../../sensors-and-actuators/sensors/hc-sr04/lib/HC-SR04/)

* [DHT11 Temperature and Humidity Sensor](../../../sensors-and-actuators/sensors/dht11/)

_Egon Teiniker, 2020-2026, GPL v3.0_
