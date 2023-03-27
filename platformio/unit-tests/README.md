# Unit Testing with PlatformIO

PlatformIO Unit Testing allows you to segregate each part of the firmware/program and test that the individual parts are working correctly.
PlatformIO builds firmware on the host machine, uploads it into a target device, starts tests and collects the test results into test reports. The final information will be shown on the host side with informative output and statistics.

We implement a **test class** in the test folder of a project:
```
unit-test/ 
      ├─── src/
      └── test/
            └── integer_test.c 
```

A test class uses the `unity.h` header file and implements **test cases** in 
seperate `test_*()` functions.

Note that `setUp()` and `tearDown()` must be implemented as well.

```C++
#include <unity.h>

void setUp(void) 
{
    // set stuff up here
}

void tearDown(void) 
{
    // clean stuff up here
}

void test_int_size(void)
{
    uint8_t size = sizeof(int);
    TEST_ASSERT_EQUAL(2, size);
}

int main( int argc, char **argv) 
{
    UNITY_BEGIN();
    RUN_TEST(test_int_size);
    UNITY_END();
}
```

In order to run the tests, the test class must be compiled and uploaded to the device.
We can do that with a simple command on the PlatformIO console:
```
platformio\unit-tests> pio test
Testing...
If you don't see any output for the first 10 secs, please reset board (press reset button)
.c:23: test_int_size    [PASSED]
--- uno:* [PASSED] Took 3.62 seconds ------------------------------------------ 

=== SUMMARY =======================================================
Environment    Test    Status    Duration
-------------  ------  --------  ------------
uno            *       PASSED    00:00:03.620
=== 1 test cases: 1 succeeded in 00:00:03.620 ======================================
```

It should be pointed out once again that **the tests run on the device** and only 
the results are displayed on the PC.
With this setting we can test code parts directly on the target platform.

In this context, the importance of a **modular implementation** (layered architectures) 
must also be pointed out.
Only in a modular design can individual parts be tested separately.

## References

* [Unit Testing](https://docs.platformio.org/en/latest/advanced/unit-testing/index.html)

* [Unit Testing of a “Blink” Project](https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html)


*Egon Teiniker, 2020-2023, GPL v3.0* 