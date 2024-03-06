# Example: Serial Task Mutex 

In FreeRTOS, semaphores and mutexes are used to manage resource 
sharing among different tasks. Although semaphores can be used for 
signaling and synchronization between tasks or between tasks and an 
interrupt, a mutex (which is a specific type of semaphore) is 
specifically designed for locking resources.

_Example:_ Creating a mutex 
```C++
SemaphoreHandle_t mutex;

void setup() 
{
    //...
    mutex = xSemaphoreCreateMutex();
    if (mutex != NULL) 
    {
      Serial.println("Mutex created");
    }
    //...
}
```

We first declare a variable `mutex` of type `SemaphoreHandle_t`. 
The `SemaphoreHandle_t` type is used to hold the reference to the semaphore 
or mutex created.

`xSemaphoreCreateMutex()` is called to create a mutex. This function attempts 
to create a new mutex and returns a handle to it. 
This handle is then stored in the mutex variable. If the creation is successful, 
mutex will be a non-NULL value, indicating that the mutex can be used to synchronize 
tasks in the program.

_Example:_ Locking the resource `Serial`

a mutex is used within task_1 to manage access to a shared resource, which 
in this case is the Arduino's Serial interface. The mutex ensures that only 
one task at a time can use the Serial interface to send messages. 

```C++
void task_1(void *pvParameter) 
{
    const char *message1 = "Hello from Task 1\n";
    while(1) 
    {
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) 
        {
            Serial.print(message1);
            xSemaphoreGive(mutex);
        }
        vTaskDelay(250 / portTICK_PERIOD_MS); 
    }
}
```

* **Semaphore Take**: At the beginning of the while loop, `task_1` attempts to 
    "take" or "acquire" the mutex using `xSemaphoreTake(mutex, portMAX_DELAY)`. 
    This function call tells FreeRTOS that `task_1` wants exclusive access to 
    the shared resource protected by the mutex.
    * The `mutex` parameter is the handle to the mutex created in the setup function.
    * The `portMAX_DELAY` parameter means that the task is willing to wait indefinitely 
    for the mutex to become available. This is a blocking call; if the mutex is already 
    owned by another task, `task_1` will be put into a blocked state until the mutex is available.

* **Accessing the Shared Resource**: If `xSemaphoreTake` returns `pdTRUE`, it means 
    `task_1` has successfully acquired the mutex. At this point, `task_1` has exclusive 
    access to the Serial interface, and it proceeds to print `message1`. No other task 
    can print to Serial until `task_1` releases the mutex.

* **Semaphore Give**: After printing to the Serial interface, `task_1` calls 
    `xSemaphoreGive(mutex)` to release the mutex. This signals to FreeRTOS that `task_1` 
    is done with the shared resource, and the mutex is now available for other tasks 
    to acquire.

By using a mutex in this way, the code ensures that **only one task at a time can access 
the `Serial` interface**, preventing concurrent access that could result in garbled output 
or data corruption. 

*Egon Teiniker, 2020-2024, GPL v3.0*    
