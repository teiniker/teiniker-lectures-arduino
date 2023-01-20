#include <Stepper.h>

// Number of steps per internal motor revolution 
const int STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const int GEAR_RED = 64;
 
// Number of steps per geared output rotation
const int STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// Connection pins to ULN2003 Motor Driver
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;
  
// Note that the pins entered in sequence 1-3-2-4  
Stepper steppermotor(STEPS_PER_REV, IN1, IN3, IN2, IN4);
 
void setup()
{
    steppermotor.setSpeed(1000);   
}
 
void loop()
{
    steppermotor.step(STEPS_PER_OUT_REV); // rotate 360° CW
    delay(1000);
  
    steppermotor.step(-STEPS_PER_OUT_REV); // rotate 360° CCW
    delay(1000);
}
