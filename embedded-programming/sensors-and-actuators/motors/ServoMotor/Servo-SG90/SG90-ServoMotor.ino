#include <Servo.h>

const int SERVO_PWM_PIN = 3;

Servo servo;

void setup(void)
{
    servo.attach(SERVO_PWM_PIN); 
} 

void loop(void)
{
    servo.write(90);  // 90°
    delay(1000);

    servo.write(0);   // 0°
    delay(1000);

    servo.write(90);  // 90°
    delay(1000);

    servo.write(180); // 180°
    delay(1000);
}
