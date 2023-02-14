const int LED_GREEN = 9; //AVRPin PB5(29)
const int LED_RED = 10; //AVRPin PB6 (30)
const int LED_BLUE = 11; //AVRPin PB7 (12)

void setup() 
{
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);  
}

void loop() 
{
  // RED
  analogWrite(LED_RED, 255);
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_BLUE, 0);
  delay(500);

  // GREEN
  analogWrite(LED_RED, 0);
  analogWrite(LED_GREEN, 255);
  analogWrite(LED_BLUE, 0);
  delay(500);

  // BLUE
  analogWrite(LED_RED, 0);
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_BLUE, 255);
  delay(500);

}
