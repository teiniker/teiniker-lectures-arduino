const int LATCH_PIN = 5;	
const int CLOCK_PIN = 6;	
const int DATA_PIN = 4;		

void update_shift_register(uint8_t leds)
{
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, leds);
    digitalWrite(LATCH_PIN, HIGH);
}

void setup() 
{
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);  
    pinMode(CLOCK_PIN, OUTPUT);
}

void loop() 
{
    update_shift_register(0x00);
    delay(500);
  
    for (uint8_t i = 0; i < 0xff; i++)	
    {
        update_shift_register(i);
        delay(500);
    }
}

