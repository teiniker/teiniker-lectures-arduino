#include "SR04.h"

const unsigned long CYCLE_TIME = 100;
unsigned long timestamp = 0;

const int TRIG_PIN = 9;
const int ECHO_PIN = 8; 

const int LED_GREEN = 2;
const int LED_YELLOW = 3;
const int LED_RED   = 4;


void setup() 
{
  // TODO
}

enum interval_t {CLOSE, NEAR, FAR, AWAY};
enum interval_t interval = AWAY;

void loop() 
{
   // TODO: Cycle Time Scheduler 

   // TODO: IO Operations
   
   // TODO: Controller Logic
}
