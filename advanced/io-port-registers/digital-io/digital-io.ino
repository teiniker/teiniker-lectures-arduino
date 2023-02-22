void setup()
{
  	DDRD |= (1 << DDD2);   // pin 2 => output
  	DDRD &= ~(1 << DDD4);  // pin 4 => input
}

void loop()
{
    bool state = PIND & (1 << PIND4);
  
  	if(state)
  		PORTD |= (1 << PORTD2);  // pin 2 = 1
	else
        PORTD &= ~(1 << PORTD2); // pin 2 = 0
}
