# Arduino Library

To create a reusable hardware abstraction, it is not enough to 
just implement the functionality. The source code must also be 
structured systematically.

## Start With a Sketch

A first implementation of a hardware abstraction usually starts 
in a sketch. The required functions or classes are implemented 
together in an `.ino` file.

This approach is also easy to simulate using Tinkercad.


## Refactor to a C/C++ Module

If the `.ino` file becomes too long, the functions or classes are 
combined into modules based on functionality.
A C/C++ module consists of a header file `.h` (declaration of 
constants, functions and classes) and an implementation file 
`.cpp` in which the actual implementations can be found.

In an Arduino project, these module files are located parallel 
to the `.ino` file in the same directory.


## Create an Arduino Library

If several Arduino projects require the same C/C++ module,  
simply copying creates a lot of code redundancy that is very 
difficult to maintain.

In this case we create an Arduino library from the C/C++ module.
We save the module in its own directory `oop-led`, together with 
application examples in an `examples` folder.

This directory is then compressed into a **ZIP file**. 
In this form, the Arduino library can easily be distributed and installed.


## References

* [Writing a Library for Arduino](https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide/)

* [Arduino Style Guide for Creating Libraries](https://docs.arduino.cc/learn/contributions/arduino-library-style-guide/)

*Egon Teiniker, 2020-2024, GPL v3.0*