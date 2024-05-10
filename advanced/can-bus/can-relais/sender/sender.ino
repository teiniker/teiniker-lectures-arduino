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

void can_send_relais(uint8_t id, uint8_t relais, uint8_t value)
{
    msg.can_id = id;
    msg.can_dlc = 4;
    msg.data[relais] = value;
    mcp2515.sendMessage(&msg);
}

void loop() 
{
    can_send_relais(0x40, 0, 1);
    delay(1000);                           
    can_send_relais(0x40, 1, 1);
    delay(1000);
    can_send_relais(0x40, 2, 1);
    delay(1000);
    can_send_relais(0x40, 3, 1);
    delay(1000);

    can_send_relais(0x40, 0, 0);
    delay(1000);                           
    can_send_relais(0x40, 1, 0);
    delay(1000);
    can_send_relais(0x40, 2, 0);
    delay(1000);
    can_send_relais(0x40, 3, 0);
    delay(1000);
}
