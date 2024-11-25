/*
 * Digital Input (Taster + LED)
 * 
 * Pin 2: ---[470]--|>|--(GND) 
 *            
 * Pin 4: -+-o\o--------(+)
 *         +------[10K]-(GND)
 */

const int LED_PIN    = 2;
const int TASTER_PIN = 4;

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
