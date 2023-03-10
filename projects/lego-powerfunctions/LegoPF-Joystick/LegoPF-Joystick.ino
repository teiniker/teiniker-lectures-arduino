#include<legopowerfunctions.h>

LEGOPowerFunctions lego(7); // Pin 7

const int X_AXIS_PIN = 0; 
const int Y_AXIS_PIN = 1; 

void setup(void)
{
  Serial.begin(115200); 
}

/*
 * Mode:      PWM
 * PWM Steps: PWM_FLT             Stop
 *            PWM_FWD1 - PWM_FWD7 Forward speed
 *            PWM_REV1 - PWM_REV7 Reverse speed
 * Channels:  CH1 - CH4          
 * Plug:      RED, BLUE
 */
void loop(void)
{
  Serial.println("Loop: ");

  uint16_t x_axis = analogRead(X_AXIS_PIN);
  uint16_t y_axis = analogRead(Y_AXIS_PIN);
  Serial.print(x_axis);
  Serial.print(",");
  Serial.println(y_axis);

  if(x_axis > 600)
  {
    lego.SingleOutput(PWM, PWM_FWD7, BLUE, CH1);  // motor forwards
  }
  else if(x_axis < 200)  
  {
    lego.SingleOutput(PWM, PWM_REV7, BLUE, CH1);  // motor backwards
  }
  else
  {
    lego.SingleOutput(PWM, PWM_FLT, BLUE, CH1); // motor stop
  }

  if(y_axis > 600)
  {
    lego.SingleOutput(PWM, PWM_FWD7, RED, CH1);  // servo forwards
  }
  else if(y_axis < 200)  
  {
    lego.SingleOutput(PWM, PWM_REV7, RED, CH1);  // servo backwards
  }
  else
  {
    lego.SingleOutput(PWM, PWM_FLT, RED, CH1); // servo stop
  }
}
