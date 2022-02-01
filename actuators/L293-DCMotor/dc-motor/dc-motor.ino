const int ENABLE = 5;
const int DIR_A = 3;
const int DIR_B = 4;

void setup() 
{
  pinMode(ENABLE,OUTPUT);
  pinMode(DIR_A,OUTPUT);
  pinMode(DIR_B,OUTPUT);
}

void loop() 
{
    digitalWrite(ENABLE,HIGH);  
    digitalWrite(DIR_A,HIGH);    
    digitalWrite(DIR_B,LOW);
    delay(1000);

    digitalWrite(ENABLE,LOW); 
    delay(1000);    

    digitalWrite(ENABLE,HIGH); 
    digitalWrite(DIR_A,LOW); 
    digitalWrite(DIR_B,HIGH);
    delay(1000);

    digitalWrite(ENABLE,LOW); 
    delay(1000);    
}
   
