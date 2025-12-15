# AVR Compilers

The `avr-gcc` and `avr-g++` compiler is a toolchain specifically designed for programming 
and compiling code for AVR microcontrollers. AVR microcontrollers are a popular family of 
microcontrollers widely used in embedded systems and Arduino boards.

The toolchain is based on the **GNU Compiler Collection (GCC)** and provides a **C++ compiler** 
`avr-g++`, a **C compiler** `avr-gcc`, and other utilities for compiling, linking, and 
debugging AVR applications.

The `avr-g++` supports features of the C++ programming language, such as classes, templates, 
and object-oriented programming. 

## C and C++ Standard Versions

The `avr-gcc` and `avr-g++` compilers version 7.3.0, released in 2018, support the following C and C++ language versions:

`avr-gcc` (C language):
* ANSI C (also known as C89 or C90)
* ISO C99

`avr-g++` (C++ language):
* C++98 (also known as C++03)
* C++11

Please note that `avr-gcc` and `avr-g++` version 7.3.0 do not support newer C++ standards 
such as C++14, C++17, or C++20. If you require support for these newer standards, you may 
need to consider using a newer version of `avr-gcc` and `avr-g++` compilers or other alternative 
toolchains that offer support for the desired C++ language versions.


## Used Optimization Flag

The used `-Os` flag is a compiler optimization option that stands for **optimize for size**. 
When we use the `-Os` flag, it instructs the compiler to prioritize reducing the size of the 
generated binary executable over optimizing for execution speed.

The `-Os` optimization level aims to produce the smallest possible code size by performing 
various optimizations, such as:

* **Removing unnecessary code**: The compiler may eliminate unused functions, variables, or 
    branches that are not essential to the program's execution.

* **Simplifying code**: It can apply simplifications and transformations to the code to reduce 
    its overall size without changing its functionality.

* **Inline expansion**: Small functions can be inlined (i.e., their code is substituted directly 
    into the calling code) to avoid the overhead of function calls.

* **Optimizing memory usage**: The compiler can try to minimize memory consumption by optimizing 
    data structures, reducing alignment requirements, or using smaller data types when possible.

* **Disabling certain optimizations**: Some optimizations that tend to increase code size may be 
    disabled to prioritize size reduction.

By using the `-Os` flag, you indicate that you are willing to sacrifice execution speed to obtain 
a smaller binary size. This can be beneficial in scenarios where code size is a significant concern, 
such as when targeting memory-constrained systems or when aiming for faster program loading and 
reduced storage requirements.

It's worth noting that the `-Os` option is just one of several optimization levels provided by the 
g++ compiler. Other common options include `-O0` (no optimization), `-O1` (basic optimizations), 
`-O2` (more aggressive optimizations), and `-O3` (maximum optimizations).


## Standard Template Library (STL)

The `avr-gcc` and `avr-g++` compilers include a **subset of the STL**, which is a collection of 
C++ template classes and functions for common data structures and algorithms. 

Some of the commonly supported components of the STL for AVR development include:

* **Containers**: `avr-g++` supports basic container classes such as `std::vector`, `std::list`, 
    `std::map`, and `std::set`. However, certain advanced container types or features that require 
    additional memory or processing resources may not be available due to the limited resources of 
    AVR microcontrollers.

* **Algorithms**: Basic algorithms like `std::sort`, `std::find`, `std::accumulate`, and `std::for_each`
     are typically supported by `avr-g++`. However, some advanced algorithms or features that rely on 
     more extensive computational capabilities may be unavailable.

* **Iterators**: `avr-g++` supports basic iterator functionality such as `std::begin` and `std::end`, 
    allowing you to use range-based for loops and iterate over container elements.

* **Utility classes**: Certain utility classes like `std::pair` and `std::tuple` are usually supported 
    by `avr-g++`.

It's important to note that due to the limited resources of AVR microcontrollers, the implementation of 
the STL in `avr-g++` may be trimmed down compared to desktop platforms. 
Some advanced features, larger container types, or memory-intensive operations may not be available or 
may have limited functionality.


## References


*Egon Teiniker, 2020-2023, GPL v3.0* 