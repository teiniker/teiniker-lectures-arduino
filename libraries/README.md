# Arduino Libraries

Arduino Libraries are a **collection of code** that makes it easy for you to connect to a sensor, 
display, module, etc.

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


## Library Manager
The Arduino IDE comes with a build-in Library Manager.
* Open the IDE and click to the **Sketch** menu and then **Include Library > Manage Libraries**.
  There, we can find a list of libraries that are already installed or ready for installation.
* Scroll the list to find the right library, click on it and select the version of the library we 
  want to install.
* Finally, click on install and wait for the IDE to install the new library.
  Once it has finished, an Installed tag should appear next to the library.
  Now we can close the library manager.

## Import a ZIP File
Libraries are often distributed as a ZIP file.
The name of the file (which includes a folder of the same name) is the name of the library.
Inside the folder will be a .cpp file, a .h file and often a keywords.txt file, examples folder, 
and other files required by the library.
* Open the IDE and click to the **Sketch** menu and then **Include Library > Add .ZIP Library...**.
* Navigate to the .zip file's location and open it.
* Return to the **Sketch > Include Library** menu and now we can see the library at the 
  bottom of the drop-down menu.
  The zip file has been expanded in the **Arduino/libraries** folder in your Arduino installation.

## Manual Installation
We can do the same steps as in "Inport a ZIP File" but manually.
* Download the library as a ZIP file and expand it.
* Move the library directory into the **Arduino/libraries** folder.
* Start the Arduino IDE, go to **Sketch > Include Library**. Verify that the library we just added 
  is available in the list.

## Used Libraries

Examples in this repository use the following libraries:

* **Sensors**
  * Ultrasonic Sensor: [HC-SR](https://github.com/teiniker/teiniker-lectures-arduino/tree/main/libraries/HC-SR04)
  * Temperature + Humidity Sensor: [DHT11](https://github.com/teiniker/teiniker-lectures-arduino/tree/main/libraries/DHT11)

* **Actuators**
  * Servo Motor: [SG90](https://github.com/teiniker/teiniker-lectures-arduino/tree/main/libraries/SG90) (Library already installed!!)
  
## References
* [Arduino Libraries](https://learn.adafruit.com/arduino-tips-tricks-and-techniques/arduino-libraries)
* [Arduino Standard Libraries](https://www.arduino.cc/en/reference/libraries)
* [Installing Additional Arduino Libraries](https://www.arduino.cc/en/guide/libraries)
* [Writing a Library for Arduino](https://docs.arduino.cc/hacking/software/LibraryTutorial)

*Egon Teiniker, 2020 - 2022, GPL v3.0* 