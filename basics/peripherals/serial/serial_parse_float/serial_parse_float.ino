
void setup() 
{
  Serial.begin(115200);                      
}

void loop() 
{    
    Serial.println("Enter an floating-point number>");

    while(Serial.available() == 0) {}  // wait  
    float value = Serial.parseFloat();

    Serial.print("value = ");
    Serial.println(value);
}

// Tip: On the serial Monitor, make sure that no LF is added.
