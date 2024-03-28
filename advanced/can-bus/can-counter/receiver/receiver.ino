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
}

void loop() 
{
    uint8_t counter;
    
    if(mcp2515.readMessage(&msg) == MCP2515::ERROR_OK)
    {
        counter = msg.data[0];

        Serial.println(counter, HEX);
    }
}
