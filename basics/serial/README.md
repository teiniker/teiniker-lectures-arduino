# Serial Communication

The `Serial` object is used for communication between the Arduino board and a computer or other devices. 
All Arduino boards have at least one serial port (also known as a **UART**). 

![Connection: PC <=> Arduino](figures/PC2Arduino.png)

It communicates on **digital pins 0 (RX)** and **1 (TX)** as well as with the computer via **USB**. 
Thus, if you use these functions, you cannot also use pins 0 and 1 for digital input or output.

We can use the Arduino environment's built-in **serial monitor** to communicate with an Arduino board. 
In the monitor, we select the same baud rate used in the call to `begin()`

A main area of application for Serial is the **logging of data or events** during program 
execution for **debugging purposes**.

_Example:_ [Tinkercad: Serial Logging](https://www.tinkercad.com/things/geaAqDXbDxK) 

![Serial output](figures/Serial-Output.png)

The `Serial` object is very useful for **sending information back from the Arduino board to the PC**. 
Sensor-signal values can be written as well as **debug information**.


## Examine C Data Types

The data types in C have **different sizes** (number of bytes used for representation) **on different platforms**.

We can use the serial port to determine the size of C data types on the Arduino platform.

_Example:_ [Tinkercad: Serial Types](https://www.tinkercad.com/things/gUoxB4xOBp1)

In order to be able to exchange C code more easily between different platforms, one should use the **C standard types**.

_Example:_ [Tinkercad: Serial Standard-Types](https://www.tinkercad.com/things/22O87tJn9Mm)


## Read Data via Serial
Data can not only be written via the serial interface. It is also possible to **send data from the PC to the Arduino board**.

_Example:_ [Tinkercad: Serial Parse Integer](https://www.tinkercad.com/things/d7wQDoFj5OQ) 

_Example:_ [Tinkercad: Serial Parse Float](https://www.tinkercad.com/things/aAU1H4Gq5DF)


## Arduino Library Functions

* **void Serial.begin(long speed)**\
    Sets the data rate in bits per second (baud) for serial data transmission.

    The parameter `speed` in bits per second (a common value is 115200).

* **size_t Serial.print(T value)**\
    Prints data to the serial port as human-readable ASCII text. 
    This command can take many forms. 
    **Integer** Numbers are printed using an ASCII character for each digit. 
    **Floats** are similarly printed as ASCII digits, defaulting to two decimal places. 
    **Bytes** are sent as a single character. 
    **Characters** and **strings** are sent as is.

    The parameter `value` is the value to print, which can be of any type `T`.

     The `format` parameter specifies the number base (for integer numbers) or number of decimal places (for floating point types).
     Possible `format` values  for integer numbers are: `DEC`, `HEX`, `OCT`, `BIN`. 
     For floating point values, `format` specifies the number of decimal places: `Serial.print(1.23456, 2)` gives `"1.23"`

     Returns the number of bytes written, though reading that number is optional.

* **size_t Serial.println(T value)**\
  **size_t print(T value, int format)**\
    Prints data to the serial port as human-readable ASCII text followed by a **carriage return** 
    character (ASCII 13, or `'\r'`) and a **newline** character (ASCII 10, or `'\n'`). 
    This command takes the same forms as `Serial.print()`.

     Prints data to the serial port as human-readable ASCII text (including `\r\n`).
     
* **int Serial.available()**\
    Get the number of bytes available for reading from the serial port. 
    This is data that’s already arrived and stored in the serial receive buffer (which holds 64 bytes).

    Returns the number of bytes available to read.

* **int Serial.read()**\
    Reads incoming serial data (one byte out of the serial receive buffer).

    Returns the first byte of incoming serial data available (or -1 if no data is available).

* **long Serial.parseInt()**\
  **long Serial.parseInt(LookaheadMode lookahead)**\
  **long Serial.parseInt(LookaheadMode lookahead, char ignore)**\
    Looks for the next valid integer in the incoming serial. The function terminates if it times out (see Serial.setTimeout()).

    Parsing stops when no characters have been read for a configurable time-out value, or a non-digit is read;
    If no valid digits were read when the time-out (see Serial.setTimeout()) occurs, 0 is returned.

    `lookahead`: The mode used to look ahead in the stream for an integer. 
    Allowed lookahead values:
    * `SKIP_ALL`: all characters other than digits or a minus sign are ignored when scanning the stream for an integer. This is the default mode.
    * `SKIP_NONE`: Nothing is skipped, and the stream is not touched unless the first waiting character is valid.
    * `SKIP_WHITESPACE`: Only tabs, spaces, line feeds, and carriage returns are skipped.

    `ignore`: Used to skip the indicated char in the search. Used for example to skip thousands divider. 

    Returns the next valid integer.

* **float Serial.parseFloat()**\
  **float Serial.parseFloat(LookaheadMode lookahead)**\
  **float Serial.parseFloat(LookaheadMode lookahead, char ignore)**\
    `Serial.parseFloat()` returns the first valid floating point number from the Serial buffer. 
    `parseFloat()` is terminated by the first character that is not a floating point number. 
    The function terminates if it times out (see `Serial.setTimeout()`).

    `lookahead`: The mode used to look ahead in the stream for a floating point number. 
    Allowed lookahead values:
    * `SKIP_ALL`: all characters other than a minus sign, decimal point, or digits are ignored when scanning the stream for a floating point number. This is the default mode.
    * `SKIP_NONE`: Nothing is skipped, and the stream is not touched unless the first waiting character is valid.
    * `SKIP_WHITESPACE`: Only tabs, spaces, line feeds, and carriage returns are skipped.

    `ignore`: used to skip the indicated char in the search. Used for example to skip thousands divider. 

* **String Serial.readString()**\
    `Serial.readString()` reads characters from the serial buffer into a String. The function terminates if it times out (see `setTimeout()`).

    Returns a `String` read from the serial buffer.


* **void Serial.setTimeout(long time)**\
    `Serial.setTimeout()` sets the maximum milliseconds to wait for serial data. 
    It defaults to 1000 milliseconds.

    `time`: timeout duration in milliseconds. 


## References

* [YouTube (Paul McWhorter): Arduino Tutorial 11: Understanding the Arduino Serial Port and Print Commands](https://youtu.be/b5kndEtAKl8)

* [YouTube (Paul McWhorter): Arduino Tutorial 18: Reading Numbers from the Serial Monitor](https://youtu.be/7aP5KL5clWA)

* [YouTube (Paul McWhorter): Arduino Tutorial 19: Reading Strings from the Serial Monitor](https://youtu.be/MAnAc_t0OrM)

* [Arduino references: Serial](https://www.arduino.cc/en/reference/serial&gt)
* [Arduino Core: HardwareSerial.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/HardwareSerial.h)
* [Arduino Core: Print.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.h)

*Egon Teiniker, 2020-2023, GPL v3.0* 
