const int ENABLE = 2;
const int DIR_A = 3;	// PWM Pin
const int DIR_B = 5;	// PWM Pin

void setup() 
{
  	Serial.begin(115200);
  
    pinMode(ENABLE,OUTPUT);
    pinMode(DIR_A,OUTPUT);
    pinMode(DIR_B,OUTPUT);
}

void loop() 
{
    digitalWrite(ENABLE,HIGH); 
    digitalWrite(DIR_A,LOW); 
    digitalWrite(DIR_B,LOW);  
  
    for(int speed=50; speed < 250; speed += 25)
    {
  	  Serial.print("Speed: ");
      Serial.println(speed);
      analogWrite(DIR_A,speed);    
      digitalWrite(DIR_B,LOW);
      delay(5000);
    }
}
