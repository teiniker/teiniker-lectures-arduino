# Arduino Libraries 

An Arduino library is a collection of code that provides **reusable functions, 
objects, and resources** to simplify programming for specific hardware components,
protocols, or functionalities in Arduino projects. 


Libraries allow developers to **extend the Arduino environment** with pre-written 
code, avoiding the need to reinvent solutions for common tasks such as controlling 
a sensor, communicating via a protocol, or driving a motor.

Structure of an Arduino Library:

* **Library Folder**: The library files are stored in a dedicated folder, named 
    after the library. For example, the library `EEPROM` would be stored in a 
    folder named `EEPROM`.

* **Header File (`.h`)**: 
    * Contains the **declarations of the classes, methods, and variables** used in 
    the library.
    * Includes preprocessor directives like `#ifndef`, `#define`, and `#endif` 
    to prevent multiple inclusions.

* **Source File (`.cpp`)**: Contains the implementation of the methods declared 
    in the header file.

* **Keywords File (`keywords.txt`)**: Optional file used to highlight keywords 
    in the Arduino IDE.

* **Examples Folder**: A folder containing example sketches showing how to use 
    the library.

* **Library Properties (`library.properties`)**: A file that contains metadata 
    about the library.


_Example_: I2C library header file [Wire.h](https://github.com/arduino/ArduinoCore-avr/blob/master/libraries/Wire/src/Wire.h)
```C++
#ifndef TwoWire_h
#define TwoWire_h

class TwoWire : public Stream
{
    //...
};

extern TwoWire Wire;

#endif    
```

_Example_: I2C library implementation file [Wire.cpp](https://github.com/arduino/ArduinoCore-avr/blob/master/libraries/Wire/src/Wire.cpp)

```C++
#include "Wire.h"

void TwoWire::begin(void)
{
  rxBufferIndex = 0;
  rxBufferLength = 0;

  txBufferIndex = 0;
  txBufferLength = 0;

  twi_init();
  twi_attachSlaveTxEvent(onRequestService); // default callback must exist
  twi_attachSlaveRxEvent(onReceiveService); // default callback must exist
}
//...
```

## Using an Arduino Library 

One of the best features of the Arduino project is the ability to add on pre-crafted 
libraries that add hardware support. 
There's tons of them, and we can pick and choose which to install. 
They're only loaded in when the sketch we are working on needs them, so for the most 
part we can download and store them for future use.

**A library is a folder with some files in it**, the files will end in `.cpp` (C++ code file) and `.h` (C++ header file).

_Example_: DHT11 Temperature + Humidity Sensor Library
```
  DHT11
  ├── dht_nonblocking.cpp
  ├── dht_nonblocking.h
  ├── examples
  │   └── DHT_nonblocking
  │       └── DHT_nonblocking.ino
  ├── keywords.txt
  ├── library.properties
  ├── LICENSE
  └── README
```

Two optional files we may see are **keywords.txt** (this is a hints file to tell the Arduino IDE how to colorize our sketch 
and **examples folder**, which may have some handy test-sketches. These will show up under the _File→Examples→Library_ dropdown.

The description and details of a library will be taken from the **library.properties** property file within a library. 

_Example:_ [Arduino Logging Library](arduino-library/logging/)

_Example:_ [Overview of the official Arduino libraries](https://reference.arduino.cc/reference/en/libraries/)


### Manual Installation
We can do all steps needed to use a library in a manual way.
* Download the library as a ZIP file and expand it.
* Move the library directory into the **Arduino/libraries** folder.
* Start the Arduino IDE, go to **Sketch > Include Library**. Verify that the library we just added 
  is available in the list.


### Import a ZIP File
Libraries are often distributed as a ZIP file.
The name of the file (which includes a folder of the same name) is the name of the library.
Inside the folder will be a `.cpp` file, a `.h` file and often a keywords.txt file, examples folder, 
and other files required by the library.
* Open the IDE and click to the **Sketch** menu and then **Include Library > Add .ZIP Library...**.
* Navigate to the `.zip` file's location and open it.
* Return to the **Sketch > Include Library** menu and now we can see the library at the 
  bottom of the drop-down menu.
  The zip file has been expanded in the **Arduino/libraries** folder in your Arduino installation.

All libraries needed to run the examples in this repository can be found in the `library` subfolders 
stored as ZIP files. 


### Library Manager
The Arduino IDE comes with a build-in Library Manager.
* Open the IDE and click to the **Sketch** menu and then **Include Library > Manage Libraries**.
  There, we can find a list of libraries that are already installed or ready for installation.
* Scroll the list to find the right library, click on it and select the version of the library we 
  want to install.
* Finally, click on install and wait for the IDE to install the new library.
  Once it has finished, an Installed tag should appear next to the library.
  Now we can close the library manager.


## Building an Arduino Library

We can also **implement our own Arduino library**. 
To do this, we will proceed step by step:

* Step 1: [Implement the functionality](../arduino-library/led-version1/) 
    We implement the desired functionality in the form of functions or classes. 
    The code is currently in an `.ino` file.

* Step 2: [Separation into `.h` and `.cpp` files](../arduino-library/led-version2/)
    We put the implementation of the functionality into a separate `.cpp` file 
    and create a header file (`.h`) to define the API.

* Step 3: [Creation of a library](../arduino-library/led-version3/)
    We create a library folder with the necessary files and structure (including
    examples). Filally we zip the library folder and import it into the Arduino IDE.

We can therefore use our own libraries in exactly the same way as libraries 
from sensor or motor manufacturers.


### Start With a Sketch

A first implementation of a hardware abstraction usually starts 
in a sketch. The required functions or classes are implemented 
together in an `.ino` file.

This approach is also easy to simulate using Tinkercad.

_Example_: [Led class in one file](led-version1/)


### Refactor to a C/C++ Module

If the `.ino` file becomes too long, the functions or classes are 
combined into modules based on functionality.
A C/C++ module consists of a header file `.h` (declaration of 
constants, functions and classes) and an implementation file 
`.cpp` in which the actual implementations can be found.

In an Arduino project, these module files are located parallel 
to the `.ino` file in the same directory.

_Example_: [Led class as mudule](led-version2/)


### Create an Arduino Library

If several Arduino projects require the same C/C++ module,  
simply copying creates a lot of code redundancy that is very 
difficult to maintain.

In this case we create an Arduino library from the C/C++ module.
We save the module in its own directory `oop-led`, together with 
application examples in an `examples` folder.

This directory is then compressed into a **ZIP file**. 
In this form, the Arduino library can easily be distributed and installed.

_Example_: [Led class as Arduino library](led-version3/)


## References

* [Arduino Libraries](https://learn.adafruit.com/arduino-tips-tricks-and-techniques/arduino-libraries)
* [Arduino Standard Libraries](https://www.arduino.cc/en/reference/libraries)
* [Installing Additional Arduino Libraries](https://www.arduino.cc/en/guide/libraries)
* [Writing a Library for Arduino](https://docs.arduino.cc/hacking/software/LibraryTutorial)

* [Writing a Library for Arduino](https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide/)

* [Arduino Style Guide for Creating Libraries](https://docs.arduino.cc/learn/contributions/arduino-library-style-guide/)

*Egon Teiniker, 2020-2025, GPL v3.0*