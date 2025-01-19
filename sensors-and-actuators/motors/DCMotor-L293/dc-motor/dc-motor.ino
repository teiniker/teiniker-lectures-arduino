const int ENABLE = 2;
const int DIR_A = 3;	
const int DIR_B = 5;	

void setup() 
{
    pinMode(ENABLE,OUTPUT);
    pinMode(DIR_A,OUTPUT);
    pinMode(DIR_B,OUTPUT);
}

void loop() 
{
    digitalWrite(ENABLE,HIGH); 
  
  	// forward
    digitalWrite(DIR_A,HIGH);    
    digitalWrite(DIR_B,LOW);
    delay(1000);

  	// stop
    digitalWrite(DIR_A,LOW);    
    digitalWrite(DIR_B,LOW);
    delay(1000);    

  	// backward
    digitalWrite(DIR_A,LOW); 
    digitalWrite(DIR_B,HIGH);
    delay(1000);

  	// stop
    digitalWrite(DIR_A,LOW);    
    digitalWrite(DIR_B,LOW);
    delay(1000);    
}
