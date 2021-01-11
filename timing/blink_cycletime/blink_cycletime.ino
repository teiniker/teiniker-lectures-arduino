/* Cycle Time Scheduling
 */

const int LED1_PIN = 7;
const int LED2_PIN = 8;

const unsigned long CYCLE_TIME = 200;
unsigned long timestamp = 0;

bool led1_flag = false;  // init value
bool led2_flag = false;  
int counter = 0; 

void setup() 
{
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}


void loop() 
{
  // Cycle Time Scheduler 
  while(millis() < timestamp + CYCLE_TIME);  
  timestamp = millis();

  // IO (read and write)
  digitalWrite(LED1_PIN, led1_flag ? HIGH : LOW);
  digitalWrite(LED2_PIN, led2_flag ? HIGH : LOW);
       
  // Control Logic
  led1_flag = !led1_flag; 

  if(counter < 4)
  {
    counter++;
  }
  else
  {
      counter = 0;
      led2_flag = !led2_flag; 
  }
}
