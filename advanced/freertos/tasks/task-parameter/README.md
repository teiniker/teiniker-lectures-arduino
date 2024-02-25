# Example: Using Task Parameter

Task parameters allow you to pass a single value or pointer to a task 
when it is created. This feature is particularly useful for passing configuration 
information, state variables, or resources like queue handles or device descriptors 
to tasks. It enables the creation of more generic and reusable task functions.

* **Lifetime of Parameters**: Ensure that any data passed to a task remains valid for 
    the lifetime of the task. This often means using static or dynamically allocated 
    memory rather than automatic (stack) memory.

* **Thread Safety**: If the task parameter points to data that might be accessed from 
    multiple tasks or interrupts, ensure access to the data is thread-safe, possibly 
    using mutexes, semaphores, or other synchronization primitives.

Using task parameters effectively can greatly enhance the modularity and flexibility 
of our FreeRTOS applications.

_Example:_ Task which gets a pointer to a `led_pin`  structure as parameter.

The `led_pin` structure holds data which is needed to configure an LED output pin.

```C++
void led_task(void *pvParameter) 
{
    led_pin *led = (led_pin *) pvParameter;

    // setup
    pinMode(led->pin, OUTPUT);

    // loop
    while(1) 
    {
        digitalWrite(led->pin, HIGH);  // LED ON
        vTaskDelay(led->delay / portTICK_PERIOD_MS);  

        digitalWrite(led->pin, LOW);  // LED OFF
        vTaskDelay(led->delay / portTICK_PERIOD_MS);      
    }
}
```

The code expects `pvParameter` to point to a structure of type led_pin (not defined 
in the snippet but implied by its usage). This structure likely contains at least 
two members:

* `pin`: An integer specifying the GPIO pin number connected to the LED.
* `delay`: An integer specifying the delay in milliseconds between changing the LED 
    state (from ON to OFF and vice versa).


_Example:_ Creating two task instanced using different parameter structures.
```C++    
led_pin led_1 ={2, 250};
led_pin led_2 ={4, 500};

void setup() 
{
    // Create the FreeRTOS tasks
    xTaskCreate(led_task, "LED1Task", 128, &led_1, 2, NULL);
    xTaskCreate(led_task, "LED2Task", 128, &led_2, 2, NULL);
}
```

In the context of a FreeRTOS application where `led_1` and `led_2` are used as 
**parameters for tasks that will run indefinitely**, it's crucial to ensure that these 
structures remain valid for the lifetime of the application. 

Defining `led_1` and `led_2` as global variables is the simplest approach. 
This ensures that they are allocated in the global data segment of your program, 
which **persists for the life of the application**.

This pattern of passing structured data to a task is a common and effective way to make 
tasks more generic and reusable, as the same task code can control different LEDs by 
passing different parameters when the task is created.



*Egon Teiniker, 2020-2024, GPL v3.0*     