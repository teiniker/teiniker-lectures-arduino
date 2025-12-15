
void setup() 
{
  Serial.begin(115200);                      
}

void loop() 
{    
    Serial.println("Enter an integer number>");

    while(Serial.available() == 0) {}  // wait  
    int value = Serial.parseInt();

    Serial.print("value = ");
    Serial.println(value, DEC);
}

// Tip: On the serial Monitor, make sure that no LF is added.
