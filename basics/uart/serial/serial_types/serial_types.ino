void setup() 
{
  Serial.begin(115200);                     
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
  Serial.print("long long: "); 
  Serial.println(sizeof(long long));                  

  // Floating point types
  Serial.print("float : "); 
  Serial.println(sizeof(float));                  
  Serial.print("double: "); 
  Serial.println(sizeof(double));                  
  Serial.print("long double: "); 
  Serial.println(sizeof(long double));                  
  
}

void loop() 
{
  // do nothing
}
