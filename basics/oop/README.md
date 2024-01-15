# Object-Oriented Programming 

Object-Oriented Programming (OOP) is a programming paradigm that uses *objects* to 
design software. It's a way of organizing and structuring software programs that 
is based on the concept of objects, which can contain **data and code**: data in 
the form of fields (often known as **attributes** or properties), and code, in the 
form of procedures (often known as **methods**).

Here are the key concepts of OOP:

* **Class**: A blueprint or template from which objects are created. A class 
defines the properties and behaviors (implementation of methods) for the objects 
that are created from it. 

* **Object**: An instance of a class. If you think of a class as a blueprint, 
an object is a single building made from that blueprint. An object contains 
state (data) and behavior (methods) defined by its class.

* **Encapsulation**: This principle is about bundling the data (attributes) 
and the methods that operate on the data into a single unit, or class. 
It also involves restricting direct access to some of an object's components, 
which is a means of preventing accidental interference and misuse of the 
methods and data.

* **Abstraction**: This concept involves hiding complex implementation details 
and showing only the necessary features of an object. It helps in reducing 
programming complexity and effort.

* **Inheritance**: This is a mechanism whereby a new class (called a **subclass** 
or derived class) is created from an existing class (called a **superclass** or 
base class). The subclass inherits the attributes and methods of the superclass, 
allowing for reuse of existing code and the addition of new features.

* **Polymorphism**: This concept allows objects of different classes to 
be treated as objects of a common superclass. It's the ability for different 
classes to be treated as instances of the same class through inheritance. 
It also refers to the ability of different methods to exist with the same 
name but potentially different implementations.

OOP languages include Java, C++, Python, and many others. Each of these 
languages implements OOP concepts in slightly different ways, but the 
underlying principles remain the same. 

OOP is widely used because it allows for **code to be modular**, 
**easier to test**, and **easier to maintain and extend** over time.


## OOP in Arduino Programming

Many parts of the **Arduino Core** and almost all **sensor libraries** are 
implemented in the form of classes.

In order to use these libraries sensibly, we need to understand the concepts 
of class and object.

If you come from C programming, you can imagine a class as a "super" structure 
that can contain operations in addition to data fields. In fact, this extension 
of structures is possible in C++, but all fields and operations are **public** 
(available without restrictions).

A class is then a C++ structure whose fields and operations are fundamentally 
**private** (not accessible). Certain operations are explicitly declared as 
public and form the **programming interface (API)**.

_Example:_ TinkerCAD: [LED Objects]()
In this example, the control of an LED is to be encapsulated in a class.

```C++
class Led
{
    private:
        uint8_t _pin;
        bool _state;

        void _setPin()
        {
            digitalWrite(_pin, _state);
        }          

    public:
        Led(uint8_t pin, bool state = false)
        {
            if(pin > 1 && pin < 14)
                _pin = pin;
            else 
                _pin = 13; // on-board LED

            _state = state; 
            pinMode(_pin, OUTPUT); 
        }

        void on(void)
        {
            _state = true;
            _setPin();
        }
  
  		void off(void)
        {
            _state = false;
            _setPin();
        }
          
        void toggle(void)
        {
            _state = !_state;
            _setPin();
        }
};
```

The `Led` class has private fields and a private method for writing 
a digital pin on the Arduino.

The constructor `Led(uint8_t pin, bool state = false)` is called when 
an instance of Led has been created and initializes the new object. 
The parameters are also checked here (input validation).

The methods `on()`, `off()` and `toggle()` change the state of a LED object 
and write the current state to the assigned Arduino pin.

To control an LED, we create an instance of the `Led` class and call the 
desired operations on this instance.

```C++
Led ledRed(2);

void loop()
{
  	ledRed.toggle();  
  	delay(250);
}
```

From a program perspective, all data and operations necessary to handle 
the LED are available via the object `ledRed``. 
No additional global variables or functions are necessary.

To use **more LEDs**, we just need to create more instances of the `Led` 
class and configure them with the appropriate Arduino pin.

```C++
Led ledRed(2);
Led ledGreen(3);
Led ledYellow(4);
Led ledBlue(5);

void loop()
{
  	ledRed.toggle();  
  	delay(250);
  	ledGreen.toggle();    
  	delay(250);                       
  	ledYellow.toggle();    
  	delay(250);                       
  	ledBlue.toggle();    
  	delay(250);                       
}
```

This results in a **modular and easily expandable structure** of our program.


## Separation of Declaration and Implementation

For libraries in the Arduino sense (actually they are modules in C/C++) there 
is a separation between the declaration of classes and functions and their implementation.

Declarations are stored in a **header file** (`Led.h`), implementations in an 
implementation file (`Led.cpp`).
The distinction between C and C++ code is based on the file extensions, `.c` for C files 
and `.cpp` for C++ files.

_Example:_ Led Library 
In this example, the `Led` class is divided into header and implementation files.
```C++
#ifndef _LED_H_
#define _LED_H_

#include <stdint.h>

class Led
{
    private:
        uint8_t _pin;
        bool _state;

    public:
        Led(uint8_t pin, bool state = false);

        void on(void);
        void off(void);
        void toggle(void);

    private: 
        void _setPin();
};
#endif
```

The pre-processor instructions (`#ifndef`, `#define`, `#endif`) are called 
**include guards** and ensure that the content of this header file is 
only inserted into the program once.

```C++
#include <Arduino.h>
#include "led.h"

Led::Led(uint8_t pin, bool state)
{
    if(pin > 1 && pin < 14)
        _pin = pin;
    else 
        _pin = 13; // on-board LED

    _state = state; 
    pinMode(_pin, OUTPUT); 
}

void Led::on(void)
{
    _state = true;
    _setPin();
}

void Led::off(void)
{
    _state = false;
    _setPin();
}

void Led::toggle(void)
{
    _state = !_state;
    _setPin();
}

void Led::_setPin(void)
{
    digitalWrite(_pin, _state);
}
```

Note the **scope operator** `::` which indicates which class an 
operation belongs to.

In an Arduino program you can save the `.h` and `.cpp` files in a 
directory parallel to the `.ino` file. 
These are then automatically taken into account during the build process.

## References
* Josh Lospinoso. **C++ Crash Course**. No Starch Press, 2019
* Bjarne Stroustrup. **The C++ Programming Language**. Pearson 4th Edition 2017

_Egon Teiniker, 2020-2024, GPL v3.0_