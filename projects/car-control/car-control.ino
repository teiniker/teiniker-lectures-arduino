#include <Servo.h>

const unsigned long CYCLE_TIME = 100;
unsigned long timestamp = 0;

// LED Pins 
const int LED_GREEN_PIN = 12;
const int LED_YELLOW_PIN = 11;
const int LED_RED_PIN = 10;

// Ultra Sonic Pins
const int TRIGGER_PIN = 9;
const int ECHO_PIN = 8;

// Servo Motor Pins
const int SERVO_PWM_PIN = 6;
Servo servo;

// DC Motor Pins
const int ENABLE = 5;
const int DIR_A = 3;
const int DIR_B = 4;


int read_distance(int triggerPin, int echoPin)
{
  // Set the trigger pin to LOW (2 microseconds)
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // Sets the trigger pin to HIGH (10 microseconds)
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Reads the echo pin and returns the sound wave travel time 
  // in microseconds
  int duration = pulseIn(echoPin, HIGH); 		
  int distance = duration/58;  
  return distance;
}

int16_t get_motor_value(void)
{
    int16_t motor = (analogRead(A0) - 1023/2)/2;
}

int16_t get_servo_value(void)
{
    int16_t servo = (unsigned long)analogRead(A1)*180/1023;
  	return servo; 
}

void leds_set(int green, int yellow, int red)
{
	digitalWrite(LED_GREEN_PIN,green);
    digitalWrite(LED_YELLOW_PIN,yellow);
    digitalWrite(LED_RED_PIN,red);  
}

void set_distance_leds(int distance)
{
 	if(distance > 100)
    {
		leds_set(LOW, LOW, LOW);		
      
    }
  	else if(distance < 100 && distance > 50)
    {
        leds_set(HIGH, LOW, LOW);      	
    }
  	else if(distance < 50 && distance > 25)
    {
     	leds_set(HIGH, HIGH, LOW); 
    }
  	else if(distance < 25)
    {
        leds_set(HIGH, HIGH, HIGH); 
    }
}  

void setup()
{
    Serial.begin(9600);
  
    pinMode(LED_GREEN_PIN, OUTPUT);  
    pinMode(LED_YELLOW_PIN, OUTPUT);  
    pinMode(LED_RED_PIN, OUTPUT);  
  
    pinMode(TRIGGER_PIN, OUTPUT);  
	pinMode(ECHO_PIN, INPUT);
  
  	servo.attach(SERVO_PWM_PIN);
}

void loop()
{
   	// Cycle Time
  	while(millis() < timestamp + CYCLE_TIME);  
  	timestamp = millis(); 
  
    int distance = read_distance(TRIGGER_PIN, ECHO_PIN);

    int16_t servo_value = get_servo_value();
 	int16_t motor_value = get_motor_value();
  	  
  	Serial.print("motor: ");
  	Serial.print(motor_value);
  	Serial.print("\t servo: ");
  	Serial.print(servo_value);
  	Serial.print("\t distance: ");
    Serial.print(distance);
    Serial.println(" cm");

	set_distance_leds(distance);
  
	servo.write(servo_value);

    if(abs(motor_value) < 25)
    {
       digitalWrite(ENABLE,LOW);   
    }
    else if(motor_value > 0)
    {
      	digitalWrite(ENABLE,HIGH);
        digitalWrite(DIR_A,HIGH);    
        digitalWrite(DIR_B,LOW);
    } 
  	else
    {
        digitalWrite(ENABLE,HIGH);
        digitalWrite(DIR_A,LOW);    
        digitalWrite(DIR_B,HIGH);      
    }
}