
void setup() 
{
  Serial.begin(115200);                      
}

void loop() 
{    
    Serial.println("Enter a string>");

    while(Serial.available() == 0) {}  // wait  
    String value = Serial.readString();

    Serial.print("value = ");
    Serial.println(value);
}

// Tip: On the serial Monitor, make sure that no LF is added.
