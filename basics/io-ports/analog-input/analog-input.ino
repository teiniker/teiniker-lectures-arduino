
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  uint16_t value = analogRead(A0); // 0 ... 1023

  float voltage = value * 5.0/1023.0;
  Serial.print(voltage);
  //Serial.println(value);
  Serial.println("[V]");
}
