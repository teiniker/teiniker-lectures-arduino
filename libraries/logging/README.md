# Logging Framework: ArduinoLog

ArduinoLog is a minimalistic framework to help the programmer output log statements to an output of choice.

In case of problems with an application, it is helpful to enable logging so that the problem can be located. 
ArduinoLog is designed so that log statements can remain in the code with minimal performance cost. In order to facilitate this the **loglevel can be adjusted**, and (if your code is completely tested) **all logging code can be compiled out**.

## Setup

To use the logging framework, just add the library stored in the **lib folder** (either import the `ArduinoLog-1.1.1.zip` file or copy the 
`ArduinoLog-1.1.1` folder into the Arduino IDE's library directory).

## Initialization

The log library needs to be initialized with the **log-level of messages** to show and the 
**log-output** - the **Serial interface**. 

Optionally, we can indicate whether to show the log-level (error `E`, warning `W`, etc.) 
for each line using the `setShowLevel()` operation.

```C
void setup() 
{
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    Log.setShowLevel(true);
    //...
}
```

Possible log levels are:
```C
#define LOG_LEVEL_SILENT  0
#define LOG_LEVEL_FATAL   1
#define LOG_LEVEL_ERROR   2
#define LOG_LEVEL_WARNING 3
#define LOG_LEVEL_INFO    4
#define LOG_LEVEL_TRACE   5
#define LOG_LEVEL_VERBOSE 6
```

## Log Events

The library allows us to log on different levels by the following operations:
```C
void fatal   (const char *format, va_list logVariables); 
void error   (const char *format, va_list logVariables);
void warning (const char *format, va_list logVariables);
void notice  (const char *format, va_list logVariables);
void trace   (const char *format, va_list logVariables);
void verbose (const char *format, va_list logVariables);
```

where the **format string** can be used to format the log-variables:
```C
    %s	display as string (char*)
    %c	display as single character
    %C  display as single character or as hexadecimal value (prefixed by `0x`) if not a printable character
    %d	display as integer value
    %l	display as long value
    %u	display as unsigned long value
    %x	display as hexadecimal value
    %X	display as hexadecimal value prefixed by `0x` and leading zeros
    %b	display as binary number
    %B	display as binary number, prefixed by `0b`
    %t	display as boolean value "t" or "f"
    %T	display as boolean value "true" or "false"
    %D,%F display as double value
```

Note that newlines are not added automatically, bt there are `...ln` versions of the logging
operations. Otherwise we have to add a `\n` to the format string.
```C
    Log.infoln("setup() done");
    Log.verbose("enter loop()\n");
```


## Logging Format

We can modify the logging format by defining a **custom prefix & suffix** for each log-line.

```C
void setup() 
{
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    Log.setPrefix(printPrefix); 
    Log.setSuffix(printSuffix);
    Log.setShowLevel(false);
    //...
}

void printPrefix(Print* _logOutput, int logLevel) 
{
    switch (logLevel)
    {
        case LOG_LEVEL_SILENT:_logOutput->print("SILENT: " ); break;
        case LOG_LEVEL_FATAL:_logOutput->print("FATAL: "  ); break;
        case LOG_LEVEL_ERROR:_logOutput->print("ERROR: "  ); break;
        case LOG_LEVEL_WARNING:_logOutput->print("WARNING: "); break;
        case LOG_LEVEL_INFO:_logOutput->print("INFO: "   ); break;
        case LOG_LEVEL_TRACE:_logOutput->print("TRACE: "  ); break;
        case LOG_LEVEL_VERBOSE:_logOutput->print("VERBOSE: "); break;
    }   
}

void printSuffix(Print* _logOutput, int logLevel) 
{
  _logOutput->print("\n");
}
```
In the given example, the prefix adds the full name of the log-level (which is
easier to grep) and the postfix adds the newline character to each log-line.


## Remove Logging Code 

If we want to fully remove all logging code, we can uncomment `#define DISABLE_LOGGING` 
in `ArduinoLog.h`, this may significantly reduce our sketch/library size because all
method implementations use a **conditional compile statement**.

```C
void Logging::setShowLevel(bool showLevel)
{
#ifndef DISABLE_LOGGING
	_showLevel = showLevel;
#endif
}
```


## References
* [YouTube: STOP using Serial.print in your Arduino code! THIS is better](https://youtu.be/--KxxMaiwSE)

* [Arduino-Log](https://www.arduino.cc/reference/en/libraries/arduinolog/)
* [GitHub: Arduino-Log](https://github.com/thijse/Arduino-Log)
