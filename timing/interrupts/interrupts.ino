const int LED_GREEN_PIN = 8;
const int LED_RED_PIN = 9;

const int BUTTON_PIN = 2;

const unsigned long CYCLE_TIME = 1000;
unsigned long timestamp = 0;

bool led_green = false;
volatile bool led_red = false;

void interrupt_service_button()
{
  	digitalWrite(LED_RED_PIN, led_red);  
	led_red = !led_red;	
}

void setup()
{
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_RED_PIN, OUTPUT);  
    pinMode(BUTTON_PIN, INPUT);

    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), interrupt_service_button, RISING);
}

void loop()
{
  	// Cyclic Timing
    while(millis() < timestamp + CYCLE_TIME);  
    timestamp = millis();
  
  	// IO Handling
  	digitalWrite(LED_GREEN_PIN, led_green);
    
  	// Processing
  	led_green = !led_green;
}
