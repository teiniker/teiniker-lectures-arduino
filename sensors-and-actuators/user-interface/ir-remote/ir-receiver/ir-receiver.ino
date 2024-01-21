#include <IRremote.hpp>

#define RECEIVER_PIN 11

#define KEY_0 0xE916FF00
#define KEY_1 0xF30CFF00
#define KEY_2 0xE718FF00
#define KEY_3 0xA15EFF00
#define KEY_4 0xF708FF00
#define KEY_5 0xE31CFF00
#define KEY_6 0xA55AFF00
#define KEY_7 0xBD42FF00
#define KEY_8 0xAD52FF00
#define KEY_9 0xB54AFF00

#define KEY_UP		0xF609FF00
#define KEY_DOWN	0xF807FF00


IRrecv irrecv(RECEIVER_PIN);     

void setup() 
{
  Serial.begin(115200);
  Serial.println("IR Receiver");
  irrecv.enableIRIn();
}

void loop()
{
	  if(IrReceiver.decode())
    {
    	  uint32_t value= IrReceiver.decodedIRData.decodedRawData;
        Serial.println(value, HEX);

      	switch(value)
        {
         	  case KEY_0: Serial.println("[0]"); break;
          	case KEY_1: Serial.println("[1]"); break;
          	case KEY_2: Serial.println("[2]"); break;
          	case KEY_3: Serial.println("[3]"); break;
          	case KEY_4: Serial.println("[4]"); break;
          	case KEY_5: Serial.println("[5]"); break;
          	case KEY_6: Serial.println("[6]"); break;
          	case KEY_7: Serial.println("[7]"); break;
          	case KEY_8: Serial.println("[8]"); break;
          	case KEY_9: Serial.println("[9]"); break;
          	case KEY_UP: Serial.println("[UP]"); break;
          	case KEY_DOWN: Serial.println("[DOWN]"); break;

          	defaul: Serial.println(value, HEX); 
        }
      
  		  irrecv.resume(); // receive the next value
    }
    delay(100);
}
