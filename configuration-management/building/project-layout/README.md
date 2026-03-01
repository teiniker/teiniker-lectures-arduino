## Project Layout 

In PlatformIO, a project is simply a structured directory that contains our source code, 
configuration, and optional testing and library components. Unlike the traditional 
single-file sketch model used in some IDEs, PlatformIO promotes a clean, modular layout 
similar to professional software projects.

A project in PlatformIO is a folder with this typical structure:

```
project/
  platformio.ini
  src/
    main.cpp
  include/
  lib/
  test/
```

* **platformio.ini**: The Project’s Control Center. This is the most important file in 
    our project. It defines:
    - Target **board(s)**
    - **Platform** (toolchain + vendor support package)
    - **Framework** (Arduino, ESP-IDF, STM32Cube, etc.)
    - Library dependencies
    - Compiler flags
    - Upload settings
    - Debug configuration
    - Serial monitor settings
    - Multiple build environments

    We can think of `platformio.ini` as the **build contract** for your project. 
    Everything needed to reproduce the build lives here, which makes projects 
    portable and CI-friendly.    

* **src/**: Application Source Code. This directory contains our main implementation 
    files. PlatformIO automatically compiles all source files in this directory.
    - Typically includes `main.cpp`
    - Can contain multiple `.cpp` files
    - We may also place headers here if they are tightly coupled to implementation 
        files

* **include/**: Project Header Files. This folder is intended for public header files 
    shared across multiple source files.
    Files in `include/` are automatically added to the compiler’s include path.

    We can use it for:
    - Interface definitions
    - Configuration headers
    - Shared constants
    - Abstract base classes

* **lib/**: Local Reusable Libraries (Optional). 
    This directory is for project-specific libraries that we want to keep modular 
    and reusable.
    PlatformIO automatically detects and builds libraries inside this directory.

    Each library typically has its own folder:

    ```
    lib/
    Sensor/
        src/
        Sensor.cpp
        Sensor.h
    Communication/
        src/
        Communication.cpp
        Communication.h    
    ```

* **test/**: This directory is used for unit testing our application.

    Each subfolder represents a test suite:

    ```
    test_math/
        test_main.cpp    
    ```    

    Unit testing is a major advantage of PlatformIO compared to many traditional 
    embedded IDEs.    


## References

* [PlatformIO](https://platformio.org/)

* [PlatformIO Documentation](https://docs.platformio.org/en/latest/)

_Egon Teiniker, 2020-2026, GPL v3.0_
