/* Timing Witout Delay
 * 
 * see: https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
 */

const int LED_PIN = 7;

unsigned long timestamp = 0;
const unsigned long INTERVAL = 500;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  if(millis() >= timestamp + INTERVAL)
  {
      timestamp = millis();
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
