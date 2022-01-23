// Digital pins
const int SWITCH_PIN = 2;
// Analog pins 
const int X_AXIS_PIN = 0; 
const int Y_AXIS_PIN = 1; 

void setup() 
{
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
  // IO Handling
  bool botton = digitalRead(SWITCH_PIN); 
  uint16_t x_axis = analogRead(X_AXIS_PIN);
  uint16_t y_axis = analogRead(Y_AXIS_PIN);

  // Serial logging
  Serial.print("X: "); 
  Serial.print(x_axis);
  
  Serial.print("\tY: "); 
  Serial.print(y_axis);

  Serial.print("\t: ");
  Serial.println(botton ? "OFF" : "ON");
   
  delay(1000);
}
