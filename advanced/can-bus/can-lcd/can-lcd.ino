#include<SPI.h>
#include<mcp2515.h>
#include <LiquidCrystal_I2C.h>

#define LCD_MESSAGE_ID0 0x60
#define LCD_MESSAGE_ID1 0x61

struct can_frame msg;
MCP2515 mcp2515(10);  // Chip Select on pin 10

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();

    lcd.init();
    lcd.backlight();
}


void msg_to_string(struct can_frame *msg, char *s)
{
    for(int i=0; i< msg->can_dlc; i++)
    {
      s[i] = (char)msg->data[i];
    }
    s[msg->can_dlc] = 0x00;
}

char lcd_string[8+1];

void loop() 
{
    if(mcp2515.readMessage(&msg) == MCP2515::ERROR_OK)
    {
        if(msg.can_id == LCD_MESSAGE_ID0)
        {
            msg_to_string(&msg, lcd_string);
            //lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("                ");
            lcd.setCursor(0,0);
            lcd.print(lcd_string);
        }
        else if(msg.can_id == LCD_MESSAGE_ID1)
        {
            msg_to_string(&msg, lcd_string);
            lcd.setCursor(0,1);
            lcd.print("                ");
            lcd.setCursor(0,1);
            lcd.print(lcd_string);
        }
    }
} 
