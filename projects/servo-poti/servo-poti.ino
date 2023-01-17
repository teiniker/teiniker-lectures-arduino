#include <Servo.h>

const int SERVO_PWM_PIN = 3;
const int POTI_ANALOG_PIN = 0; 

Servo servo;

void setup(void)
{
    Serial.begin(9600);
    //servo.attach(SERVO_PWM_PIN);
    servo.attach(SERVO_PWM_PIN, 400, 2600);
} 

void loop(void)
{
    uint16_t poti = analogRead(POTI_ANALOG_PIN);
    uint8_t pos = map(poti, 0, 1023, 0, 180);
    Serial.println(pos);
    servo.write(pos);	  
}
