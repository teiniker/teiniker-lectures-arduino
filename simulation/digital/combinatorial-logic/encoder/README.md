# Simulation: Arduino LED Blinking


![Arduino Blink](arduino-led.png)

```C++
const int LED_PIN = 2;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(1000); 
  digitalWrite(LED_PIN, LOW);
  delay(1000); 
}
```


## References
* [Thinkercad](https://www.tinkercad.com/things/2eObGT5jGVY)

* [Electronics Hub: Binary Encoders And Their Applications](https://www.electronicshub.org/binary-encoder/)


*Egon Teiniker, 2020-2021, GPL v3.0* 
