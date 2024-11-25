# Arduino Core and Libraries

Arduino Libraries are a **collection of code** that makes it easy for you to connect to a sensor, 
display, module, etc.


## Arduino Core

The Arduino Core is a set of configurations and code libraries that realizes an hardware abstraction 
layer commonly used to program and interact with Arduino boards. 

It includes definitions for the various I/O functions, as well as the implementation of the Arduino 
language (a set of C/C++ functions) that simplifies programming for these devices. The core provides 
essential support for standard Arduino functions like `digitalRead()`, `digitalWrite()`, and `analogRead()`, 
making it easier for beginners and hobbyists to develop projects involving sensors, motors, and other 
peripherals. 

The concept of a **Hardware Abstraction Layer (HAL)** is an essential component in both system 
software and embedded systems design. The HAL acts as an intermediary layer that provides a consistent 
and simplified interface to interact with hardware. This abstraction allows software applications and 
higher-level system components to operate independently of specific hardware details. 

Here are some key aspects of a HAL:

* **Simplification of Software Development**: By using a HAL, developers can write code at a higher level 
  of abstraction without worrying about the intricacies of the hardware. 
  This makes software development faster and more efficient.

* **Portability**: Software designed with a HAL is more portable across different hardware platforms. 
  Since the hardware-specific code is confined to the HAL, only this layer needs to be adapted for new 
  hardware, while the rest of the software remains unchanged.

* **Hardware Independence**: HAL enables software to run on different hardware platforms without requiring 
  modifications. It achieves this by abstracting the details of the hardware, like CPU architecture or 
  peripheral devices, behind a uniform interface.

* **Consistency**: It provides a consistent programming interface across various hardware platforms, 
  which is particularly beneficial in environments where multiple hardware configurations are common, 
  such as in embedded systems, consumer electronics, or computing devices.

* **Enhanced Security and Stability**: By isolating the hardware from the software, a HAL can also improve 
  system stability and security. Faults or vulnerabilities at the hardware level can be contained within 
  the HAL, reducing the risk to the overall system.


The Arduino Core is an integral part of the Arduino ecosystem, **ensuring compatibility and ease of use across a wide 
range of Arduino boards**:

* [avr-core](avr-core/)
* [arduino-esp32](https://github.com/espressif/arduino-esp32)


## Arduino Library Structure

One of the best features of the Arduino project is the ability to add on pre-crafted libraries that add hardware support. 
There's tons of them, and we can pick and choose which to install. 
They're only loaded in when the sketch we are working on needs them, so for the most part we can download and 
store them for future use.

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


## Manual Installation
We can do all steps needed to use a library in a manual way.
* Download the library as a ZIP file and expand it.
* Move the library directory into the **Arduino/libraries** folder.
* Start the Arduino IDE, go to **Sketch > Include Library**. Verify that the library we just added 
  is available in the list.


## Import a ZIP File
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


## Library Manager
The Arduino IDE comes with a build-in Library Manager.
* Open the IDE and click to the **Sketch** menu and then **Include Library > Manage Libraries**.
  There, we can find a list of libraries that are already installed or ready for installation.
* Scroll the list to find the right library, click on it and select the version of the library we 
  want to install.
* Finally, click on install and wait for the IDE to install the new library.
  Once it has finished, an Installed tag should appear next to the library.
  Now we can close the library manager.

  
## References
* [Arduino Libraries](https://learn.adafruit.com/arduino-tips-tricks-and-techniques/arduino-libraries)
* [Arduino Standard Libraries](https://www.arduino.cc/en/reference/libraries)
* [Installing Additional Arduino Libraries](https://www.arduino.cc/en/guide/libraries)
* [Writing a Library for Arduino](https://docs.arduino.cc/hacking/software/LibraryTutorial)

*Egon Teiniker, 2020 - 2023, GPL v3.0* 
