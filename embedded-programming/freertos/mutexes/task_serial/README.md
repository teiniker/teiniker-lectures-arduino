# Accessing Serial from two Tasks Using a Mutex

## Implementation

On ESP32 (including ESP32-C6), `setup()` itself already runs inside a FreeRTOS 
task (the Arduino main task).

```C++
SemaphoreHandle_t serialMutex;

void setup() 
{
    // ...

    // Create mutex 
    serialMutex = xSemaphoreCreateMutex();
    if (serialMutex == NULL) 
    {
        Serial.println("Failed to create Serial mutex!");
        return;
    }

    // ... 
}

```

* **Global mutex handle**: SemaphoreHandle_t serialMutex
    - Declares a **FreeRTOS semaphore handle**
    - Must be created before any task uses it

* **Create a mutex**: `serialMutex = xSemaphoreCreateMutex()`
    - Allocates and initializes a FreeRTOS mutex
    - Stored in the global handle serialMutex
    - This mutex will be used to serialize access to Serial
    
* **Checks whether mutex creation failed** (out of heap memory)


To demonstrate the overlap of two tasks when outputting via Serial, the characters 
are printed individually (with small pauses):

```C++
void task1(void *parameter) 
{
    while(1) 
    {
        xSemaphoreTake(serialMutex, portMAX_DELAY);
        Serial.print("[");
        for(int i = 0; i < 80; i++) 
        {
            Serial.print("A");
            vTaskDelay(pdMS_TO_TICKS(5));
        }
        Serial.println("]");
        xSemaphoreGive(serialMutex);

        vTaskDelay(pdMS_TO_TICKS(500)); 
    }
}
```

* **Take the mutex (critical section begins)**: `xSemaphoreTake(serialMutex, portMAX_DELAY)`
    - Blocks until the mutex is available
    - `portMAX_DELAY` means:
        - Wait forever
        - No timeout 
    - Once this returns:
        - This task owns the mutex
        - No other task can access Serial

* **Release the mutex (critical section ends)**: `xSemaphoreGive(serialMutex)`
    - Releases ownership
    - Another waiting task can now use `Serial`
    - Memory changes are visible to the next owner

Note that this task intentionally holds the mutex **too long**: 
- Printing + delays inside the critical section
- Useful for demonstration

We can see from the output that there is no longer any overlap between the tasks:

```
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
```



## References

* [YouTube (Digi-Key Electronics): Introduction to RTOS Part 6 - Mutex](https://youtu.be/I55auRpbiTs?si=yWZW_ZxEEZqv_vaa)

*Egon Teiniker, 2020-2025, GPL v3.0* 