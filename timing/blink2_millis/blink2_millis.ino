/* Timing Witout Delay - Control two LEDs
 * 
 * see: https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
 */

const int LED1_PIN = 7;
const int LED2_PIN = 8;

const unsigned long TIMER_INTERVAL = 500;
unsigned long last_timestamp = 0;

bool led1_flag = false;  // init value
bool led2_flag = false;  
int led_counter = 0; 

void setup() 
{
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}


void loop() 
{
  // Timing 
  while(millis() - last_timestamp < TIMER_INTERVAL); // wait until intervall is over 
  last_timestamp = millis();

  // IO 
  digitalWrite(LED1_PIN, led1_flag ? HIGH : LOW);
  digitalWrite(LED2_PIN, led2_flag ? HIGH : LOW);
       
  // Control Logic
  led1_flag = !led1_flag; 

  if(led_counter < 4)
  {
    led_counter++;
  }
  else
  {
      led_counter = 0;
      led2_flag = !led2_flag; 
  }
}
