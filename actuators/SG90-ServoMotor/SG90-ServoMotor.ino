#include <Servo.h>

const int SERVO_PWM_PIN = 3;

Servo myservo;

void setup(void)
{
  myservo.attach(SERVO_PWM_PIN); 
} 

void loop(void)
{
  myservo.write(90);  // 90°
  delay(1000);

  myservo.write(0);   // 0°
  delay(1000);

  myservo.write(90);  // 90°
  delay(1000);

  myservo.write(180); // 180°
  delay(1000);
}
