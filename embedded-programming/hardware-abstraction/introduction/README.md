# Hardware Abstraction 

Hardware abstraction is a concept in computing and software engineering that 
involves **creating an abstraction layer between the software** (like an 
operating system or an application) **and the physical hardware** of a computer 
system. This abstraction layer allows software to interact with the hardware 
in a general or simplified way, rather than needing to directly manage the details 
and complexities of the hardware.


## Layered Architecture

The separation between hardware and the rest of the system is given, at least 
once the hardware is defined.
But because of technology advances the hardware will change over time.

A problem is that there is nothing that keeps hardware knowledge from polluting 
all the code so the code will be very hard to change.

**Software and firmware intermingling is an anti-pattern**.


### Hardware Abstraction Layer 

The **line between software and firmware** is typically not so well defined
as the line between code and hardware.
One of our jobs as an embedded software developer is to firm up that line.

![Embedded Architecture Layers](figures/Embedded-Architecture-Layered.png)

The name of the boundary between the software and the firmware is the 
**Hardware Abstraction Layer (HAL)**.

The HAL exists for the software that sits on top of it, and its API should 
be tailored to that software’s needs. 

Here are some key aspects of a HAL:

* **Simplification of Software Development**: By using a HAL, developers can 
    write code at a higher level of abstraction without worrying about the 
    intricacies of the hardware. 
    This makes software development faster and more efficient.

* **Portability**: Software designed with a HAL is more portable across different 
    hardware platforms. Since the hardware-specific code is confined to the HAL, 
    only this layer needs to be adapted for new hardware, while the rest of the 
    software remains unchanged.

* **Hardware Independence**: HAL enables software to run on different hardware 
    platforms without requiring modifications. It achieves this by abstracting 
    the details of the hardware, like CPU architecture or peripheral devices, 
    behind a uniform interface.

* **Consistency**: It provides a consistent programming interface across various 
    hardware platforms, which is particularly beneficial in environments where 
    multiple hardware configurations are common, such as in embedded systems, 
    consumer electronics, or computing devices.

* **Enhanced Security and Stability**: By isolating the hardware from the software, 
    a HAL can also improve system stability and security. Faults or vulnerabilities 
    at the hardware level can be contained within the HAL, reducing the risk to 
    the overall system.

## References

* Robert C. Martin. **Clean Architecture: A Craftsman's Guide to Software Structure and Design**.
    Addison-Wesley, 2017
    - Chapter 29: Clean Embedded Architecture

*Egon Teiniker, 2020-2025, GPL v3.0*
