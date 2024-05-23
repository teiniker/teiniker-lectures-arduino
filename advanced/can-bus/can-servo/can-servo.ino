#include<SPI.h>
#include<mcp2515.h>
#include <Servo.h>

#define SERVO_MESSAGE_ID 0x50

struct can_frame msg;
MCP2515 mcp2515(10);  // Chip Select on pin 10

const int SERVO_PWM_PIN = 3;
Servo servo;

void setup() 
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();

    servo.attach(SERVO_PWM_PIN); 
}


void loop() 
{
    if(mcp2515.readMessage(&msg) == MCP2515::ERROR_OK)
    {
        if(msg.can_id == SERVO_MESSAGE_ID)
        {
            int angle = msg.data[0];
            if(angle < 0)
              angle = 0;
            if(angle > 180)
              angle = 180;              
            servo.write(angle);  
        }
    }
    
} 
