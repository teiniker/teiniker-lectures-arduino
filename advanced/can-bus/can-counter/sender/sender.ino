#include<SPI.h>
#include<mcp2515.h>

uint8_t counter = 0;
struct can_frame msg;
MCP2515 mcp2515(10);  // Chip Select on pin 10

void setup() 
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();
}

void loop() 
{
    counter++;
    msg.can_id = 0x33;
    msg.can_dlc = 8;
    msg.data[0] = counter;
    msg.data[1] = 0x00;
    msg.data[2] = 0x00;
    msg.data[3] = 0x00;
    msg.data[4] = 0x00;
    msg.data[5] = 0x00;
    msg.data[6] = 0x00;
    msg.data[7] = 0x00;

    mcp2515.sendMessage(&msg);
    delay(1000);                            
}
