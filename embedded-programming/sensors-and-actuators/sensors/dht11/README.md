# DHT11 Temperature and Humidity Sensor 

The DHT11 is a composite Sensor which contains a **calibrated digital signal output** of the **temperature** 
and **humidity**. Maintainer: Adafruit

The sensor includes a resistive moisture sensor and a NTC temperature measurement devices, 
and connects with a **8-bit microcontroller**.


## Wiring Diagram 

The connections are: Voltage, Ground and Signal which can be connected to any digital pin on our Arduino.

![DHT11](dht11.png)


## Source Code

We have to install the [**Adafruit_Sensor library**](https://github.com/teiniker/teiniker-lectures-arduino/tree/main/libraries/DHT11) and the 
[**DHT11 library**](https://github.com/teiniker/teiniker-lectures-arduino/tree/main/libraries/DHT11) 
to use the `DHT.h` header file.

In the used library a cass named `DHT` has been implemented.
To use the sensor module, we hav to create an instance of that class.
The constructur gest two parameters, the used Arduino pin `DHT_SENSOR_PIN`
and the sensor type `DHT11`.

```C
#include "DHT.h"

const int DHT_SENSOR_PIN = 2;
DHT dht(DHT_SENSOR_PIN, DHT11);

void setup(void)
{
    Serial.begin(9600);
    dht.begin();
}

void loop(void)
{
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
  
    Serial.print("T = " );
    Serial.print(temperature, 1);
    Serial.print(" °C; H = " );
    Serial.print(humidity, 1);
    Serial.println("%" );

    delay(2000); // Wait a few seconds between measurements.
}
```

Using the library methods `readTemperature()` and `readHumidity()` we get the measurement data
in `[°C]` and `[%]` as floating-point numbers.

Reading temperature or humidity takes about 250 milliseconds. In the example we read new
values every 2 seconds from the sensor module.


## Library Operations

* **DHT(uint8_t pin, uint8_t type, uint8_t count = 6)**\
    Constructor of the DHT class.
    * pin: pin number that sensor is connected
    * type: type of sensor
    * count: number of sensors

* **void begin(uint8_t usec = 55)**\
    Setup sensor pins and set pull timings
    *  usec: Optionally pass pull-up time (in microseconds) before DHT reading starts. 
        Default is 55.

* **float readTemperature(bool S = false, bool force = false)**\
    Read temperature and return the Temperature value in selected scale.
    * S: Scale. Boolean value (true = Fahrenheit; false = Celcius)
    * force: true if in force mode
 
* **float readHumidity(bool force = false)**\
    Read Humidity and return a float value - humidity in percent.
    * force: force read mode

* **float convertCtoF(float c)**\
    Converts Celcius to Fahrenheit and return a float value in Fahrenheit. 
    * c: value in Celcius

* **float convertFtoC(float f)**\
    Converts Fahrenheit to Celcius and float value in Celcius.
    * f: value in Fahrenheit
 
Note that reading temperature or humidity takes about **250 milliseconds**!

## References
* [YouTube (Circuit Basics):](https://youtu.be/oZ-oFY6TiPw)
* [YouTube (Paul McWhorter): Arduino Tutorial 50: How to Connect and Use the DHT11 Temperature and Humidity Sensor](https://youtu.be/-AvF2TsB2GI)
* [YouTube (DroneBot Workshop): Measuring Temperature with Arduino - 5 Sensors](https://youtu.be/fjVbcaKW2r0)

* [DHT11, DHT22 and AM2302 Sensors](https://learn.adafruit.com/dht)
* [Arduino: DHT sensor library](https://www.arduino.cc/reference/en/libraries/dht-sensor-library/)
 
* [GitHub: Adafruit Unified Sensor Driver](https://github.com/adafruit/Adafruit_Sensor)
* [GitHub: DHT sensor library](https://github.com/adafruit/DHT-sensor-library)

*Egon Teiniker, 2020 - 2022, GPL v3.0* 
