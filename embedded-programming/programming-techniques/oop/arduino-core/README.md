# OOP in the AVR Core
  
The Arduino core is written in C++ and demonstrates various OOP
techniques. However, not all C++ features are utilized; notably, 
the Standard Template Library (STL) is avoided. The following sections
provides an overview of the C++ features employed in the core, 
together with some examples.


## From C to C++

### Namespaces
    
_Example:_ [cores/arduino/new](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/new)

```C++
namespace std {
    struct nothrow_t {};
    extern const nothrow_t nothrow;

    using size_t = ::size_t;
} // namespace std
```

### Function Overloading

_Example:_ [cores/arduino/Arduino.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h)

```C++
long random(long);
long random(long, long);
```

### Default Arguments

_Example:_ [cores/arduino/Arduino.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h)

```C++
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
```


### Name Mangling

_Example:_ [cores/arduino/Arduino.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h)

```C++
#ifdef __cplusplus
extern "C"{
#endif

//..

#ifdef __cplusplus
} // extern "C"
#endif
```


## Object-Oriented Programming 


### Constructor and Method Overloading


_Example:_ [cores/arduino/WString.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/WString.h)

```C++
class String
{
    // Constructor Overloading
    String(const char *cstr = "");
	String(const String &str);
    
    // Method Overloading
	int indexOf( char ch ) const;
	int indexOf( char ch, unsigned int fromIndex ) const;
	int indexOf( const String &str ) const;
	int indexOf( const String &str, unsigned int fromIndex ) const;
	int lastIndexOf( char ch ) const;
	int lastIndexOf( char ch, unsigned int fromIndex ) const;
	int lastIndexOf( const String &str ) const;
	int lastIndexOf( const String &str, unsigned int fromIndex ) const;
	String substring( unsigned int beginIndex ) const { return substring(beginIndex, len); };
	String substring( unsigned int beginIndex, unsigned int endIndex ) const;
    //...
};
```

_Example:_ [cores/arduino/Print.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.h)
```C++
class Print
{
    // Method Overloading
    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);
    size_t print(const Printable&);

    size_t println(const __FlashStringHelper *);
    size_t println(const String &s);
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(const Printable&);
    size_t println(void);
    //...
};
```

_Example:_ [cores/arduino/IPAddress.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/IPAddress.h)

```C++
class IPAddress : public Printable {
public:
    // Constructor Overloading    
    IPAddress();
    IPAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet);
    IPAddress(uint32_t address);
    IPAddress(const uint8_t *address);

    // Method Overloading
    bool fromString(const char *address);
    bool fromString(const String &address) { return fromString(address.c_str()); }
    //...
};    
```

### Inheritance 

_Example:_ HardwareSerial Serial 

- [cores/arduino/Print.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.h)

    ```C++
    class Print
    {
        size_t print(const __FlashStringHelper *);
        size_t print(const String &);
        size_t print(const char[]);
        size_t print(char);
        //...
    };
    ```

- [cores/arduino/Stream.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Stream.h)

    ```C++
    class Stream : public Print
    {
        //...
    };
    ```

- [cores/arduino/HardwareSerial.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/HardwareSerial.h)

    ```C++
    class HardwareSerial : public Stream
    {
        //...
    };

    #if defined(UBRRH) || defined(UBRR0H)
    extern HardwareSerial Serial;
    #define HAVE_HWSERIAL0
    #endif
    ```

## Abstract Methods

_Example:_ [cores/arduino/Print.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.h)

```C++
class Print
{
    //...
    virtual size_t write(uint8_t) = 0;
};
```


_Example:_ [cores/arduino/Printable.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Printable.h)

```C++
class Printable
{
public:
    virtual size_t printTo(Print& p) const = 0;
};
```

### Operator Overloading

_Example:_ [cores/arduino/Printable.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Printable.h)

```C++
    // Overloaded equals operator
    bool operator==(const IPAddress& addr) const { return _address.dword == addr._address.dword; };
    bool operator==(const uint8_t* addr) const;

    // Overloaded index operator to allow getting and setting individual octets of the address
    uint8_t operator[](int index) const { return _address.bytes[index]; };
    uint8_t& operator[](int index) { return _address.bytes[index]; };

    // Overloaded copy operators to allow initialisation of IPAddress objects from other types
    IPAddress& operator=(const uint8_t *address);
    IPAddress& operator=(uint32_t address);
```


## See Also...

_Example:_ [Arduino Library: Wire (I2C)](https://github.com/arduino/ArduinoCore-avr/tree/master/libraries/Wire)
- class `TwoWire`
    - Inheritance
    - Method overloading
    - Default arguments
    - Object creation: `TwoWire Wire;`

_Example:_ [Arduino Library: SoftwareSerial](https://github.com/arduino/ArduinoCore-avr/blob/master/libraries/SoftwareSerial/src/SoftwareSerial.h)
- class `SoftwareSerial`
    - Inheritance
    - Static fields
    - Static methods
    
_Example:_ [Arduino Library: SPI](https://github.com/arduino/ArduinoCore-avr/blob/master/libraries/SPI/src/SPI.h)
- class `SPISettings`
    - Constructor overloading
    - Private methods

- class `SPIClass` 
    - Static methods
    - Static fields
    - Object creation: `SPIClass SPI;`


## References

* [GitHub: ArduinoCore-avr](https://github.com/arduino/ArduinoCore-avr/)

_Egon Teiniker, 2020-2026, GPL v3.0_