/*
 * Digital Input (Taster + LED)
 * 
 * Pin 7: ---[1K]--|>|--(GND) 
 *            
 * Pin 8: -+-o\o--------(+)
 *         +------[10K]-(GND)
 */

const int LED_PIN    = 7;
const int TASTER_PIN = 8;

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(TASTER_PIN, INPUT);        
}

void loop() 
{
    int state = digitalRead(TASTER_PIN);

    if(state)
      digitalWrite(LED_PIN, HIGH);      
    else      
      digitalWrite(LED_PIN, LOW);       

}
