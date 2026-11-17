# Using Serial.printf()

On the **ESP32**, you can use **`Serial.printf()`**, just like on the 
**Raspberry Pi Pico (Arduino version)**.

## Using `Serial.printf()` on ESP32
The ESP32 **Arduino core** supports **`printf` formatting** with the 
`Serial.printf()` method, making it easier to print formatted strings 
to the serial monitor.

_Example:_ Using  Serial.printf()

```cpp
void setup() 
{
    Serial.begin(115200);  // Start Serial communication at 115200 baud

    int number = 42;
    float pi = 3.14159;
    
    Serial.printf("Hello ESP32!\n");
    Serial.printf("The answer is: %d\n", number);
    Serial.printf("Pi to 3 decimal places: %.3f\n", pi);
}
```

Benefits of using `Serial.printf()`:
* It eliminates the need for **concatenating strings** using `String` or 
    `char[]`, reducing heap fragmentation.
* It supports **format specifiers** (`%d`, `%f`, `%s`, etc.), just 
    like `printf()` in C.
* It's more **efficient** than multiple `Serial.print()` calls.

## Common Format Specifiers

| Format | Description | Example |
|--------|------------|---------|
| `%d`   | Integer (decimal) | `Serial.printf("Number: %d\n", 42);` |
| `%u`   | Unsigned integer | `Serial.printf("Unsigned: %u\n", 42U);` |
| `%x`   | Hexadecimal (lowercase) | `Serial.printf("Hex: %x\n", 255);` |
| `%X`   | Hexadecimal (uppercase) | `Serial.printf("Hex: %X\n", 255);` |
| `%f`   | Floating point | `Serial.printf("Float: %.2f\n", 3.14159);` |
| `%c`   | Character | `Serial.printf("Char: %c\n", 'A');` |
| `%s`   | String (char array) | `Serial.printf("String: %s\n", "Hello");` |

**Notes**:
* Unlike standard `printf()`, ESP32's `Serial.printf()` **does not fully 
    support `%f` for floating-point numbers** unless **enabled** in some 
    cases. 
    
    If `%f` doesn't work, use:
    ```cpp
    Serial.print("Pi: ");
    Serial.println(3.14159, 3); // Prints 3.142
    ```
* Make sure **Serial.begin()** is called before using `Serial.printf()`.


