/* Simple Scheduler using millis()
 * 
 * see: https://www.norwegiancreations.com/2017/09/arduino-tutorial-using-millis-instead-of-delay/
 */

const int LED1_PIN = 7;
const int LED2_PIN = 8;

unsigned long timestamp_1 = 0;
unsigned long timestamp_2 = 0;

const unsigned long INTERVAL_1 = 500;
const unsigned long INTERVAL_2 = 250;

void task_1(void);
void task_2(void);

void setup()
{
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

void loop() 
{
  if(millis() >= timestamp_1 + INTERVAL_1)
  {
      timestamp_1 = millis();
      task_1();
  }

  if(millis() >= timestamp_2 + INTERVAL_2)
  {
      timestamp_2 = millis();
      task_2();
  }

  //...
}

// Tasks
void task_1(void)
{
   digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
}

void task_2(void)
{
   digitalWrite(LED2_PIN, !digitalRead(LED2_PIN));
}
