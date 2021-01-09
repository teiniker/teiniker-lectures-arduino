/* Timing Witout Delay
 * 
 * see: https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
 */

const int LED_PIN = 7;
const unsigned long TIMER_INTERVAL = 500;
unsigned long last_timestamp = 0;

bool led_flag = false;  // init value

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
}


void loop() 
{
  // Timing 
  while(millis() - last_timestamp < TIMER_INTERVAL); // wait until intervall is over 
  last_timestamp = millis();

  // IO 
  digitalWrite(LED_PIN, led_flag ? HIGH : LOW);
       
  // Control Logic
  led_flag = !led_flag; 
  //delay(400);  // additional delay (< TIMER_INTERVAL) has no effect!!
}
