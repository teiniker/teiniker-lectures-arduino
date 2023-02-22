// Digital pins
const int SWITCH_PIN = 2;
// Analog pins 
const int X_AXIS_PIN = 0; 
const int Y_AXIS_PIN = 1; 

void setup() 
{
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() 
{
  // IO Handling
  bool botton = digitalRead(SWITCH_PIN); 
  float x_axis = analogRead(X_AXIS_PIN)*5.0/1023.0 - 2.5;
  float y_axis = analogRead(Y_AXIS_PIN)*5.0/1023.0 - 2.5;

  // Serial logging
  Serial.print(x_axis);
  Serial.print(" ");
  Serial.print(y_axis);
  Serial.print(" ");
  Serial.println(botton ? 0.0 : 5.0);
   
  delay(100);
}
