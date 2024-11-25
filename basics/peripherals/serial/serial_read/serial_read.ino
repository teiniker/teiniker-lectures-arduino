#define LF 0x0A

char buffer[80];
uint8_t index = 0;

void setup() 
{
  Serial.begin(115200);                     
  Serial.println("Enter a message>");
}

void loop() 
{    
    if(Serial.available() > 0) 
    {
        buffer[index] = Serial.read();
        if(buffer[index] == LF)
        {
            buffer[index] = 0x00;
            Serial.print("Received message: ");
            Serial.println(buffer);

            // reset
            index = 0;  
        }
        else
        {
          index++;
        }
    }
}
