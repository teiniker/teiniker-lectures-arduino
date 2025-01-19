void setup() 
{
  Serial.begin(115200);                     
  Serial.println("Arduino: standard integer types");  

  // Signed integer types 
  Serial.print("int8_t : "); 
  Serial.println(sizeof(int8_t));                  
  Serial.print("int16_t: "); 
  Serial.println(sizeof(int16_t));                  
  Serial.print("int32_t: "); 
  Serial.println(sizeof(int32_t));                  
  Serial.print("int64_t: "); 
  Serial.println(sizeof(int64_t));                  

  // Unsigned integer types 
  Serial.print("uint8_t : "); 
  Serial.println(sizeof(uint8_t));                  
  Serial.print("uint16_t: "); 
  Serial.println(sizeof(uint16_t));                  
  Serial.print("uint32_t: "); 
  Serial.println(sizeof(uint32_t));                  
  Serial.print("uint64_t: "); 
  Serial.println(sizeof(uint64_t));                  
}

void loop() 
{
  // do nothing
}
