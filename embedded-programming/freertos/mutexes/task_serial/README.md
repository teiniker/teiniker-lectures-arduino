# Accessing Serial from two Tasks Using a Mutex





## Implementation

To demonstrate the overlap of two tasks when outputting via Serial, the characters 
are printed individually (with small pauses):

```C++
void task1(void *parameter) 
{
    while(1) 
    {
        Serial.print("[");
        for(int i = 0; i < 80; i++) 
        {
            Serial.print("A");
            vTaskDelay(pdMS_TO_TICKS(5));
        }
        Serial.println("]");
        
        vTaskDelay(pdMS_TO_TICKS(500)); 
    }
}
```

```C++
void task2(void *parameter) 
{
    while(1) 
    {
        Serial.print("*");
        vTaskDelay(pdMS_TO_TICKS(250));
    }
}
```

With this implementation, we can observe how the two tasks interrupt each other, 
resulting in interleaved output:

```
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA*AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA*]
*[A*AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA*AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAA*AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA*AAAAAAAAAA]
**[AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA*AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA]
...
```


## References


