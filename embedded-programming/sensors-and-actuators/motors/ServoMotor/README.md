# Servo Motors

Servo is a type of geared motor that can only **rotate 180 degrees**. 

A standard hobby servo typically consists of a **small electric motor, a potentiometer, control electronics, and a gearbox**. 
The position of the output shaft is constantly measured by the internal potentiometer and compared with the target position 
set by the controller (e.g. the Arduino).

![Servo Motor](figures/ServoConcept.jpg)
_([Makerguides](https://www.makerguides.com/servo-arduino-tutorial/))_

According to the error, the control electronics adjust the actual position of the output shaft so that it matches the 
target position. This is known as a closed-loop control system.

Servo motors are controlled by sending a **PWM (pulse-width modulation) signal to the signal line of the servo**. 

The width of the pulses determines the position of the output shaft:
* When we send the servo a signal with a pulse width of **1.5 milliseconds (ms)**, 
    the servo will move to the **neutral position (90 degrees)**. 
* The min **(0 degrees) and max (180 degrees)** position typically correspond to a pulse width of **1 ms and 2 ms** respectively. 

![Servo Motor](figures/ServoControl.png)
_([Makerguides](https://www.makerguides.com/servo-arduino-tutorial/))_

Note this can vary slightly between different types and brands of servo motors (e.g. 0.5 and 2.5 ms). Many servos only rotate through about 170 degrees (or even only 90) but the middle position is almost always at 1.5 ms.

Servo motors generally expect a pulse every **20 milliseconds or 50 Hz** but many RC servos work fine in a range of 40 to 200 Hz.

## Examples

The following examples show the use of servo motors together with an 
Arduino Uno board.

* **Tinkercad**: [Arduino: Motor Servo](https://www.tinkercad.com/things/0q3C1mj7NeS) 

* **Example**: [Servo Motor SG90](Servo-SG90)



## Library Operations

We use the **build-in library** related to the `Servo.h` header file.

A servo is activated by creating an instance of the `Servo` class passing the desired pin to the `attach()` method.
The servos are pulsed in the background using the value most recently written using the `write()` method.

*  **uint8_t attach(int pin)**\
    Attaches a servo motor to an I/O pin which provides PWM (attach the given pin to the next free channel, sets pinMode)
    Returns channel number or INVALID_SERVO if failure.

* **uint8_t attach(int pin, int min, int max)**\
    Attaches to a pin setting min and max values in microseconds default min is 544, max is 2400. 

*  **void write(int value)**\
    Sets the servo angle in degrees (if value is < 200 its treated as an angle, otherwise as pulse width in microseconds).

* **void writeMicroseconds(int value)**\
    Sets the servo pulse width in microseconds. 

* **int read()**\
    Gets the last written servo pulse width as an angle between 0 and 180 degrees. 

* **int readMicroseconds()**\
    Gets the last written servo pulse width in microseconds. 

* **bool attached()**\
    Returns true if there is a servo attached, otherwise false. 

* **void detach()**\
    Stops an attached servos from pulsing its I/O pin. 

Note that `analogWrite()` of PWM on pins associated with the timer are disabled when the first servo is attached.


## References
* [YouTube (Paul McWhorter): Arduino Tutorial 30: Understanding and Using Servos in Projects](https://youtu.be/aFHu65LiFok)

* [YouTube (DroneBot Workshop): Using Servo Motors with Arduino](https://youtu.be/kUHmYKWwuWs)
* [DroneBot Workshop: Using Servo Motors with the Arduino](https://dronebotworkshop.com/servo-motors-with-arduino/)

* [How to control servo motors with Arduino](https://www.makerguides.com/servo-arduino-tutorial/)

* [GitHub: Servo Library for Arduino](https://github.com/arduino-libraries/Servo)


*Egon Teiniker, 2020 - 2023, GPL v3.0*
