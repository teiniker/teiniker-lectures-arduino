void setup() 
{
  Serial.begin(9600);                     
  Serial.println("Arduino: gcc types");  

  // Integer types 
  Serial.print("char : "); 
  Serial.println(sizeof(char));                  
  Serial.print("short: "); 
  Serial.println(sizeof(short));                  
  Serial.print("int  : "); 
  Serial.println(sizeof(int));                  
  Serial.print("long : "); 
  Serial.println(sizeof(long));                  

  // Floating point types
  Serial.print("float : "); 
  Serial.println(sizeof(float));                  
  Serial.print("double: "); 
  Serial.println(sizeof(double));                  
  
}

void loop() 
{
  // do nothing
}
