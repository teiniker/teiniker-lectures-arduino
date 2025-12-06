void setup() 
{
    Serial.begin(115200);                     
    Serial.println("Hello from ESP32!");  
}

void loop() 
{
  Serial.println("ON");                   
  delay(1000);                             
  Serial.println("OFF");                  
  delay(1000);                            
}
