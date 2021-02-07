const int IN1_PIN = 2;
const int IN2_PIN = 3;
const int IN3_PIN = 4;
const int IN4_PIN = 5;

void setup() 
{
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);        
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);        

}

void loop() 
{
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);      
  
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, LOW);      
  delay(3000);                       
  
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);      

  digitalWrite(IN3_PIN, HIGH);
  digitalWrite(IN4_PIN, LOW);      
  delay(3000);                       
  
}
