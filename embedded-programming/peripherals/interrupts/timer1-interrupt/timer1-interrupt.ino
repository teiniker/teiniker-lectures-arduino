#define LED_PIN 2

ISR(TIMER1_COMPA_vect) 
{
  // 
  digitalWrite(LED_PIN, digitalRead(LED_PIN) ^ 1); // Toggle LED state
}


void setup() 
{
  Serial.begin(115200);  
  pinMode(LED_PIN, OUTPUT);

  // Disable all interrupts
  noInterrupts();           

  // Clear registers
  TCCR1A = 0;
  TCCR1B = 0;

  // 15625 = 16MHz / (1024 * 1Hz) - 1 (must be less than 65536)
  OCR1A = 15624;            

  // Turn on CTC mode
  TCCR1B |= (1 << WGM12);   

  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  

  // Enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A); 

  // Enable all interrupts
  interrupts(); 
}

void loop() 
{
  Serial.print("ping...");
  delay(5000);
  Serial.println("pong");
}