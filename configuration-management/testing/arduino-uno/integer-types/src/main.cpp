#include <Arduino.h>

void setup() 
{
    Serial.begin(115200);                     
    Serial.println("Integer Types:");

    Serial.print("    Size of bool: ");
    Serial.println(sizeof(bool));

    Serial.print("    Size of short: "); 
    Serial.println(sizeof(short));

    Serial.print("    Size of int: ");
    Serial.println(sizeof(int));    

    Serial.print("    Size of long: ");
    Serial.println(sizeof(long));

    Serial.print("    Size of long long: ");
    Serial.println(sizeof(long long));
}

void loop() 
{
}
