const int LED_PIN = D2; // external LED pin (XIAO ESP32C3 has no built-in LED)

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
