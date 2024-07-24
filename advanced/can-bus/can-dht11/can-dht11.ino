#include<SPI.h>
#include<mcp2515.h>
#include <DHT.h>

MCP2515 mcp2515(10);  // Chip Select on pin 10
DHT dht(4, DHT11);    // DHT11 Signal on Pin D4

void setup() 
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();

    Serial.begin(9600);
    dht.begin();
}

void can_send_temperature(struct can_frame *msg, float temp)
{
    msg->can_id = 0x60;
    msg->can_dlc = 7;
    dtostrf(temp, 3, 1, (char*)msg->data);
    msg->data[4] = ' ';
    msg->data[5] = 'C';
    msg->data[6] = '\0';

    mcp2515.sendMessage(msg);
}

void can_send_humidity(struct can_frame *msg, float humid)
{
    msg->can_id = 0x61;
    msg->can_dlc = 7;
    dtostrf(humid, 3, 1, (char*)msg->data);
    msg->data[4] = ' ';
    msg->data[5] = '%';
    msg->data[6] = '\0';
    mcp2515.sendMessage(msg);
}


void loop() 
{
    // Measurement
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();    
 
    // Send data via CAN
    struct can_frame msg;
    can_send_temperature(&msg, temperature);
    can_send_humidity(&msg, humidity);    

    delay(5000);                            
}
