#include<SPI.h>
#include<mcp2515.h>

struct can_frame msg;
MCP2515 mcp2515(10);  // Chip Select on pin 10

void setup() 
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();

    Serial.begin(9600);
    Serial.println("CAN-Bus Scanner ... started.");
}


void log_can_msg(struct can_frame *msg)
{
    char s[35];
    sprintf(s, "CAN: %02x|%x|", msg->can_id, msg->can_dlc);
    for(uint8_t i = 0; i<8; i++)
    {
        if(i < msg->can_dlc)
        {
          sprintf(s+10+i*3, "%02x ", msg->data[i]);
        }
        else
        {
          sprintf(s+10+i*3, "-- ");
        }
    }
    Serial.println(s);
}


void loop() 
{
    if(mcp2515.readMessage(&msg) == MCP2515::ERROR_OK)
    {
        log_can_msg(&msg);
    }
} 
