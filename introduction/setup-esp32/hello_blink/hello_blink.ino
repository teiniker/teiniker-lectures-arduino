const int LED_PIN = D2; // Define the LED pin

void setup() 
{
    pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
    digitalWrite(LED_PIN, HIGH);   
    delay(200);                         
    digitalWrite(LED_PIN, LOW);     
    delay(200);                         
}
