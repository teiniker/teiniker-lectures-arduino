uint32_t counter;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Initialize my Arduino counter!");
  counter = 0;
}

void loop() 
{
  Serial.print("Counter = ");
  Serial.println(counter++, BIN);
}
