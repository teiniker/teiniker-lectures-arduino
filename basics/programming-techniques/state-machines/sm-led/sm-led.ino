const int LED_PIN = 2;
const int SWITCH_ON_PIN = 9;
const int SWITCH_OFF_PIN = 8;

// Events 
enum events
{
    SWITCH_ON,
    SWITCH_OFF
};
enum events event = SWITCH_OFF;

// State Machine States
enum sm_states 
{
    OFF,
    ON
};

enum sm_states state = OFF; 
void sm_led(enum events event);
void sm_led_handler_off(enum events event);
void sm_led_handler_on(enum events event);

// Activities
int led_status = LOW;

void setup() 
{
    pinMode(LED_PIN, OUTPUT);
  	pinMode(SWITCH_ON_PIN, INPUT);
  	pinMode(SWITCH_OFF_PIN, INPUT);
}

void loop() 
{
 	// TODO: Cyclic Processing 
  
  	// IO Handling
    digitalWrite(LED_PIN, led_status);
	
  	if(digitalRead(SWITCH_ON_PIN) == HIGH)
      event = SWITCH_ON; 
  	else if(digitalRead(SWITCH_OFF_PIN) == HIGH)
      event = SWITCH_OFF;
  	  
	// Processing
    sm_led(event);
}

// State Machine 
void sm_led(enum events event)
{
    switch(state)
    {
        case OFF:
            sm_led_handler_off(event);
            break;

        case ON:
            sm_led_handler_on(event);
            break;
    }
}

// Handle Events in State: OFF
void sm_led_handler_off(enum events event)
{
    switch(event)
    {
        case SWITCH_ON:
            led_status = HIGH;
            state = ON;
        break;

        case SWITCH_OFF:
        break;
    }
}

// Handle Events in State: ON
void sm_led_handler_on(enum events event)
{
    switch(event)
    {
        case SWITCH_ON:
        break;

        case SWITCH_OFF:
            led_status = LOW;
            state = OFF;
        break;
    }
}
