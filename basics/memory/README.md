# Arduino Memory

One essential part of a microcontroller is its memory which stores information 
temporarily or permanently in microcontrollers, and can be used for several purposes. 

Arduino boards are mainly based on two families of microcontrollers: AVR and ARM. 
While **AVR** family microcontrollers are based on the **Harvard architecture** model, 
**ARM** family microcontrollers can be based on either **von Neuman or Harvard architectures** models.

There are three types of Arduino memory that you should be aware of:

* **Flash or Program Memory (PROGMEM)**\
    Flash memory is a type of memory that is used for storage, similar to what we see in USB thumb drives and SD cards. It is **non-volatile**, meaning that it will retain stored information even if no power is supplied.

    In an Arduino, Flash is used to **store the program code** and any additional data. Since data held in flash memory can’t be modified by executing code, they are first copied into the SRAM before the code is run.

* **SRAM – Static Random Access Memory**\
    SRAM is arguably the most important component of diagnosing memory issues in Arduino. You can imagine it as a memory block that is shared amongst three main components:
    * **Static Data**: This section of the SRAM stores data such as **global and static variables**.
    * The **Heap** exists next to static data and is used for dynamically allocated data items, such as variables created by executing code.
    * **Stack**: The stack is used to keep track of **function parameters**, including **local variables** for interrupts, and function calls. Each function call will increase the size of the stack, while returning from a function will return that memory to the free memory pool.
    
    The stack and heap segments are located on opposite ends of the free memory.
    Most memory problems are the result of the **stack and heap colliding**, which can cause a corruption of the data held in memory.

* **EEPROM – Electronically Erasable Programmable Read-Only Memory**\
    EEPROM is another form of **non-volatile** memory that you can use to read and write data. However, you will have to do so byte by byte.

    Most EEPROMs have lifespan of around **100,000 write/erase cycles**, so be careful with placing EEPROM read / writes in loops!



## Measure Arduino Memory Usage

Before optimisations, we’ll have to begin our diagnosis by measuring the amount of memory that our program uses.

* **Flash**: Whenever we compile or upload your code, the IDE will show you exactly how much memory is being used by your upload and what percentage of the selected board’s memory that uses.

_Example:_ TODO

* **SRAM**: To measure the usage of our Arduino’s SRAM, we can use a freeMemory() function call from the arduino library which measures the free RAM available.

_Example:_ TODO

* **EEPROM**: We have to write to the EEPROM byte by byte, so we should know exactly which addresses are being used in our program. 

_Example:_ [EEPROM Data Memory](eeprom/)


## References

* [Arduino Memory Guide](https://docs.arduino.cc/learn/programming/memory-guide)
* [Managing Arduino Memory: Flash, SRAM, EEPROM!](https://www.seeedstudio.com/blog/2021/04/26/managing-arduino-memory-flash-sram-eeprom/#:~:text=There%20are%20three%20types%20of,Erasable%20Programmable%20Read%2DOnly%20Memory)

*Egon Teiniker, 2020-2023, GPL v3.0* 