#include "SR04.h"

const unsigned long CYCLE_TIME = 100;
unsigned long timestamp = 0;

const int TRIG_PIN = 9;
const int ECHO_PIN = 8; 

const int LED_GREEN = 2;
const int LED_YELLOW = 3;
const int LED_RED   = 4;

SR04 sensor = SR04(ECHO_PIN,TRIG_PIN);
long distance;

void setup() 
{
  pinMode(LED_RED, OUTPUT); 
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);    

  Serial.begin(9600);
}

enum interval_t {CLOSE, NEAR, FAR, AWAY};
enum interval_t interval = AWAY;

void led_display(void);

void loop() 
{
   // Cycle Time Scheduler 
   while(millis() < timestamp + CYCLE_TIME);  
   timestamp = millis();

   // IO Operations
   distance = sensor.Distance();
   Serial.print(distance);
   Serial.println("cm");    
   led_display(); 
   
   // Controller Logic
   if(distance < 10) // 0cm to 10cm [0,10)
   {
      interval = CLOSE;
   }
   else if(distance >= 10 && distance < 20)  // 10cm to 20cm [10,20)
   {
      interval = NEAR;
   }
   else if(distance >= 20 && distance < 30) // 20cm to 30cm [20,30)
   {
      interval = FAR; 
   }
   else // 30cm to ... 
   {
      interval = AWAY;
   }      
}

void led_display(void)
{
    switch(interval)
    {
      case CLOSE:
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_RED, HIGH);      
      break;

      case NEAR:
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_RED, LOW);      
      break;

      case FAR:
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);    
      break;

      case AWAY:
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);    
      break;
    }  
}
