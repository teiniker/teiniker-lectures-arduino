# Servo Motor SG90

The SG90 Micro Servo motor is a tiny and lightweight with high output power.
The Servo can rotate approximately 180 degrees (90 in each direction), 
and works just like the standard kinds but smaller.

## Wiring Diagram 

The Servo has three wires, of which the **brown** one is the **ground wire** and should be connected to the 
GND port of UNO, the **red** one is the **power wire** and should be connected to the 5V port, and the 
**orange** one is the **signal wire** and should be connected to the digital pin 3 (use a PWM pin).

![Servo Motor](figures/SG90-Servo.png)


## Source Code

To control the servo motor we will be using the `Servo.h` library which comes **pre-installed** with the Arduino IDE.

```C
#include <Servo.h>

const int SERVO_PWM_PIN = 3;

Servo servo;

void setup(void)
{
    servo.attach(SERVO_PWM_PIN); 
} 

void loop(void)
{
    servo.write(90);  // 90°
    delay(1000);

    servo.write(0);   // 0°
    delay(1000);

    servo.write(90);  // 90°
    delay(1000);

    servo.write(180); // 180°
    delay(1000);
}
```
In the **setup()** section of the code, we `attach()` the servo object that we created to the pin that will control the servo. 

In the first part of the **loop()** function, we simply tell the servo motor to move to a particular angle with the 
function `write()`. 
Note that we need a delay between the commands to give the servo motor some time to move to the set position.

## Simulation

**Tinkercad**: [Arduino: Motor Servo](https://www.tinkercad.com/things/0q3C1mj7NeS) 


## References


*Egon Teiniker, 2020 - 2023, GPL v3.0*
