/* Analog Input (Poti)
 *  
 * see: https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
 */

#define PIN_POTI A0

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int value = analogRead(PIN_POTI); // 0 ... 1023

  float voltage = value * 5.0/1023.0;
  Serial.print(voltage);
  //Serial.println(value);
  Serial.println("[V]");
}
