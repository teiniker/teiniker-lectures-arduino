# Setup Arduino IDE

The easiest way to program the Arduino board is with the **Arduino IDE**. 

This is a very simple development environment that comes with all the tools needed 
to write the source code, compile it and load it onto the Arduino board.

* Download the Arduino IDE: Go to [download](https://www.arduino.cc/en/software) and
    save the current version of the ZIP file, e.g. `arduino-1.8.19-windows.zip`

* Unzip the `arduino-1.8.19-windows.zip` file in a local folder.

* Open the `arduino-1.8.19` folder and execute `arduino.exe` - that's it!


# Run the Blink Sketch

The Arduino IDE always shows exactly one `*.ino` file, also known as **sketch**, per window. 
With **File/Open** you can open a new window with a new source file.
    
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

## References

* [Arduino IDE Download](https://www.arduino.cc/en/software)
* [Getting Started with Arduino products](https://www.arduino.cc/en/Guide)

* [YouTube (Paul McWhorter): Arduino Tutorial 1: Setting Up and Programming the Arduino for Absolute Beginners](https://youtu.be/fJWR7dBuc18)


*Egon Teiniker, 2020-2022, GPL v3.0* 