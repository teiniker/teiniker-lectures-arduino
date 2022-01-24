# HC-SR04 Ultrasonic Distance Sensor

The sensor module HC-SR04 provides 2cm-400cm non-contact measurement function, the 
ranging accuracy can reach to 3mm. 

The modules includes ultrasonic transmitters, receiver and control circuit. 

![HC-SR04 Timing Diagram](hc-sr04-timing.png)

The Timing diagram shows that we only need to supply a short 10us pulse to the trigger 
input to start the ranging, and then the module will send out an 8 cycle burst of ultrasound at 
40 kHz and raise its echo. 

The Echo pulse width is proportional to the distance of the object, or range. 
We can calculate through the time interval between sending trigger signal and receiving 
echo signal: 

us / 58 = centimeters or: the range = high level time * velocity (340M/S) / 2; 

we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.


## Wiring Diagram 

The connections are: Voltage, Ground, Trigger and Echo. Trigger and Echo can be connected to any digital pin on our Arduino.

![HC-SR04](hc-sr04.png)


## Source Code

We have to install the **HC-SR04 library**, to use the `SR04.h` header file.

The library implements a class named `SR04` which we can use to do the measurement.
We need two digital Arduino pins `ECHO_PIN` and `TRIG_PIN` which are passed into the constructor.

```C
#include <SR04.h>

const int TRIG_PIN = 9;
const int ECHO_PIN = 8; 

SR04 sr04(ECHO_PIN,TRIG_PIN);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
   long distances = sr04.Distance();
   Serial.print(distances);
   Serial.println(" cm");    
   delay(250); 
}
```



## Library Operations

This library is used for measuring distance with the HC-SR04 that measures distances from 2 to 400cm. 

* void begin(uint8_t triggerPin, uint8_t echoPin)

* double* measureDistanceCm()

* double* measureDistanceMm()


















## References

* [Arduino: HC-SR04](https://www.arduino.cc/reference/en/libraries/hc-sr04/)
* [GitHub: Arduino/ESP8266/ESP32 library for HC-SR04 ultrasonic distance sensor](https://github.com/d03n3rfr1tz3/HC-SR04)

*Egon Teiniker, 2020 - 2022, GPL v3.0* 