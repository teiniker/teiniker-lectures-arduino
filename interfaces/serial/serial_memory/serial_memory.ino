#include <stdlib.h>

int global_variable;
int global_variable_initialized = 0;


void setup() 
{
    int local_variable;
    static int static_variable;
    static int static_variable_initialized = 0;
    int *heap_ptr = malloc(sizeof(int));
    
  Serial.begin(9600);

  Serial.println("Arduino Memory Segments:");

  
   free(heap_ptr);
}

void loop() 
{
}
