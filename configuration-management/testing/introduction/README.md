# Unit Testing with PlatformIO

PlatformIO supports unit testing with the **Unity framework**.  
The idea is simple: test small, isolated parts of your firmware and execute 
those tests automatically.

In a typical embedded setup, PlatformIO will:
1. Build the test firmware on your computer.
2. Upload it to the target board.
3. Run the tests on the board.
4. Print the results in the terminal.


## Project Layout

Place production code in `src/` and test code in `test/`:

```text
project/
├── src/
└── test/
    └── test_file.cpp
```

PlatformIO discovers test files inside `test/` automatically.


## Writing a Test

Each test case is usually a function named `test_*()`.  
The file must include `unity.h` and call Unity's runner macros.

```cpp
#include <unity.h>

void setUp(void) {
    // Called before each test function
}

void tearDown(void) {
    // Called after each test function
}

void test_int_size(void) {
    uint8_t size = sizeof(int);
    TEST_ASSERT_EQUAL(2, size);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_int_size);
    return UNITY_END();
}
```

`setUp()` and `tearDown()` are part of the Unity interface and should 
be present, even if empty.


## Running Tests

Run all tests for the default environment:

```bash
pio test
```

Run tests for a specific environment (for example `uno`):

```bash
pio test -e uno
```

Typical output:

```text
Testing...
If you don't see any output for the first 10 secs, please reset board (press reset button)
.pio/build/uno/test/test_main.c:23:test_int_size:PASS
----------------------- uno:* [PASSED] Took 3.62 seconds -----------------------

=================================== SUMMARY ===================================
Environment    Test    Status    Duration
-------------  ------  --------  ------------
uno            *       PASSED    00:00:03.620
================== 1 test cases: 1 succeeded in 00:00:03.620 ==================
```

Important: in this mode, tests run on the device, not on the host PC.  
The PC only shows logs and a summary.


## Design Recommendation

Unit tests work best with modular code:
- Keep hardware-independent logic in small functions/modules.
- Separate business logic from hardware access where possible.
- Test modules in isolation.

This makes applications easier to verify, maintain, and evolve.

## References

- [PlatformIO: Unit Testing](https://docs.platformio.org/en/latest/advanced/unit-testing/index.html)
- [Unit Testing of a Blink Project](https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html)

_Egon Teiniker, 2020-2026, GPL v3.0_
