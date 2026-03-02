# PlatformIO CLI

PlatformIO Core (CLI tool) is the heart of the entire PlatformIO ecosystem, it is written in Python,
and provides a rich and documented Command Line Interface (CLI).


# Use the PlatformIO Terminal inside VS Code

* Open VS Code

* Open your PlatformIO project

* Click [New Terminal] on the status bar

On this command line, we can use the following commands:

```bash
# build project
$ pio run 

# verbose build output
$ pio run -v

# clean build   		
$ pio run -t clean && pio run 

# Find the serial port:
$ pio device list

# Upload (deploy):
$ pio run -t upload

# Upload on a particular port
$ pio run -t upload --upload-port /dev/ttyACM0

# Serial monitor
$ pio device monitor
$ pio device monitor -p /dev/ttyACM0 -b 115200

# Test (remote unit testing)
$ pio test 
$ pio test -e uno --upload-port /dev/ttyACM0

# Static code analysis (cppcheck)
$ pio check 

# Size report
$ pio run -t size
```


## References

* [PlatformIO Core (CLI)](https://docs.platformio.org/en/latest/core/index.html)

*Egon Teiniker, 2020-2026, GPL v3.0* 