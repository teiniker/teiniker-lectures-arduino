#include<SPI.h>
#include<mcp2515.h>

#define RELAIS_MESSAGE_ID 0x40
struct can_frame msg;
MCP2515 mcp2515(10);  // Chip Select on pin 10

#define RELAIS_1 4
#define RELAIS_2 5
#define RELAIS_3 6
#define RELAIS_4 7

void setup() 
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();

    Serial.begin(9600);
    
    relais_init();
}


void relais_init(void)
{
    pinMode(RELAIS_1, OUTPUT);
    pinMode(RELAIS_2, OUTPUT);
    pinMode(RELAIS_3, OUTPUT);
    pinMode(RELAIS_4, OUTPUT);
    digitalWrite(RELAIS_1, HIGH);
    digitalWrite(RELAIS_2, HIGH);
    digitalWrite(RELAIS_3, HIGH);
    digitalWrite(RELAIS_4, HIGH);
}

void relais_set_values(uint8_t relais, uint8_t value)
{
    int relais_value = (value == 0) ? HIGH : LOW;  // Inverted relais logic
    
    switch(relais)
    {
        case 0x00: 
          digitalWrite(RELAIS_1, relais_value);
          break;

        case 0x01: 
          digitalWrite(RELAIS_2, relais_value);
          break;

        case 0x02: 
          digitalWrite(RELAIS_3, relais_value);
          break;

        case 0x03: 
          digitalWrite(RELAIS_4, relais_value);
          break;
    }
}

void process_can_message(struct can_frame *msg)
{
    // Fist 4 bytes set the relais: 01 00 00 00 
    for(uint8_t i=0; i<4; i++)
    {
        relais_set_values(i, msg->data[i]);
    }
}


void loop() 
{
    if(mcp2515.readMessage(&msg) == MCP2515::ERROR_OK)
    {
        if(msg.can_id == RELAIS_MESSAGE_ID)
        {
           process_can_message(&msg);
        }
        else
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
} 
