#include<SPI.h>
#include<mcp2515.h>
#include <DHT.h>

struct can_frame msg;
MCP2515 mcp2515(10);  // Chip Select on pin 10
DHT dht(4, DHT11);    // DHT11 Signal on Pin D4

void setup() 
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();

    dht.begin();
}

void map_uint32(uint8_t *data, uint32_t value)
{
    uint8_t *ptr = (uint8_t *)&value;
    for(uint8_t i=0; i<sizeof(value); i++)
    {
        data[i] = *(ptr+i);
    }
}

void loop() 
{
    uint32_t temperature = (int)(dht.readTemperature()*10.0);
    uint32_t humidity = (int)(dht.readHumidity()*10.0);    

    msg.can_id = 0x33;
    msg.can_dlc = 8;
    map_uint32(msg.data, temperature);
    map_uint32(msg.data + 4, humidity);
    mcp2515.sendMessage(&msg);

    delay(1000);                            
}
