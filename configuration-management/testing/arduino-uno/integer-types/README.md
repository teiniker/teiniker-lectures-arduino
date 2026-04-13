# Example: Integer-Types Test 

This example **verifies the size of integer types** on an Arduino Uno.

Test cases are located in the `test/test_integer_types.cpp` file.
Note that a separate binary is generated and deployed for the test cases.

No additional configurations in the `platformio.ini` file are necessary.

## Test Execution 

```bash
$ pio test 

test\test_integer_types.cpp:52: test_size_bool          [PASSED]
test\test_integer_types.cpp:53: test_size_short         [PASSED]
test\test_integer_types.cpp:54: test_size_int           [PASSED]
test\test_integer_types.cpp:55: test_size_long          [PASSED]
test\test_integer_types.cpp:56: test_size_longlong      [PASSED]
---- uno:* [PASSED] Took 8.51 seconds --------------------------
```

*Egon Teiniker, 2020-2026, GPL v3.0* 
