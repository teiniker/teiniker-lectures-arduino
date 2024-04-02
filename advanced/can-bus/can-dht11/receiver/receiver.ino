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
    if(mcp2515.readMessage(&msg) == MCP2515::ERROR_OK)
    {
        Serial.print("CAN:");
        Serial.print(msg.can_id, HEX);
        Serial.print(":");
        Serial.print(msg.can_dlc, HEX);  
        Serial.print(":");
        for(uint8_t i = 0; i<8; i++)
        {
            Serial.print(msg.data[i], HEX);
            Serial.print(" ");
        }
        Serial.println("");
    }
} 
