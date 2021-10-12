void setup() 
{
  Serial.begin(9600);                     
  Serial.println("Hello from Arduino!");  
}

void loop() 
{
  Serial.println("ON");                   
  delay(1000);                             
  Serial.println("OFF");                  
  delay(1000);                            
}
