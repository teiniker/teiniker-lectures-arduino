#include<SPI.h>
#include<mcp2515.h>

// Digital pins
const int SWITCH_PIN = 5;
// Analog pins 
const int X_AXIS_PIN = 0; 
const int Y_AXIS_PIN = 1; 

struct can_frame msg;
MCP2515 mcp2515(10);  // Chip Select on pin 10

void setup() 
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();

    Serial.begin(9600);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
}


void loop() 
{
    // IO Handling
    bool button = digitalRead(SWITCH_PIN); 
    uint32_t x_axis = analogRead(X_AXIS_PIN);
    uint32_t y_axis = analogRead(Y_AXIS_PIN);

    uint8_t x_value = x_axis * 180 / 1023;
    uint8_t y_value = y_axis * 180 / 1023;
    uint8_t button_value = button;
    
    msg.can_id = 0x50;
    msg.can_dlc = 2;
    msg.data[0] = x_value;
    msg.data[1] = y_value;

    mcp2515.sendMessage(&msg);
    delay(100);                            
}
