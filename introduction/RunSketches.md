# Run an Arduino Sketch

The Arduino IDE always shows exactly one `*.ino` file, also known as **sketch**, per window. 
With **File/Open** you can open a new window with a new source file.

## Introduction 

A sketch is a C/C++ file, but it has a predefined structure:
```C
void setup() 
{
    // Initial settings
}

void loop() 
{
    // Recurring activities
}
```
Although we can use regular `#include` directives, the `Arduino.h` header file is 
implicitly included.


## LED Hello World Sketch 
Now it's time to connect the Arduino board to the PC using a USB cable.
Check in the **Tools menu** whether the correct Arduino board has been recognized at the correct **COM port**.

To start an **LED version of the Hello World program**:
* Open the file: `teiniker-lectures-arduino\introduction\blink_hello\blink_hello.ino`
* Compile and upload this sketch.
* Now the on-board LED should blink.

```C
void setup() 
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(200);                         
    digitalWrite(LED_BUILTIN, LOW);     
    delay(200);                         
}
```
The flashing frequency can be changed by changing the parameter values of the `delay()` function (in ms).

## Serial Hello World Sketch

A big advantage of the Arduino platform is that you can send data back to the PC from a sketch via the 
**serial interface**. With this you can implement a simple debugging and logging.

```C
void setup() 
{
  Serial.begin(115200);                     
  Serial.println("Hello from Arduino!");  
}

void loop() 
{
  Serial.println("ON");                   
  delay(1000);                             
  Serial.println("OFF");                  
  delay(1000);                            
}
```

Serial is an object defined in the `HardwareSerial.h` file (included with `Arduino.h`). 
The `start()` method defines the transmission speed (baud rate).
Different data types can be sent with the `print(`) method. `println()` adds a line break.

In order to display the data sent via the serial interface on the PC, the **monitor window** must be opened.

Make sure the **baud rates** in Sketch and in the Monitor window are the same!


## References

* [Getting Started with Arduino products](https://www.arduino.cc/en/Guide)
* [YouTube (Paul McWhorter): Arduino Tutorial 1: Setting Up and Programming the Arduino for Absolute Beginners](https://youtu.be/fJWR7dBuc18)

*Egon Teiniker, 2020-2022, GPL v3.0* 