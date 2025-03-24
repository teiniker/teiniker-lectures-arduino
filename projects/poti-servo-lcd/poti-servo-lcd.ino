#include <Wire.h> 
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Digital pins
const int SWITCH_PIN = 2;
// Analog pins 
const int X_AXIS_PIN = 0; 
const int Y_AXIS_PIN = 1; 

// Servo pin
const int SERVO_PWM_PIN = 3;

// LCD object: address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servo motor object
Servo servo;

// Scheduling
unsigned long timestamp = 0;
const unsigned long CYCLE_TIME = 100; // [ms]


void setup() 
{
  // Joystick button
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  
	// Initialize the LCD
	lcd.init();
	lcd.backlight();

  // Initialize Servo motor
  servo.attach(SERVO_PWM_PIN);

  // UART output
  Serial.begin(115200);
}

void loop() 
{
  // Cycle Time Scheduler 
  while(millis() < timestamp + CYCLE_TIME);  
  timestamp = millis();


  // IO Handling
  bool botton = digitalRead(SWITCH_PIN); 
  uint16_t poti_1 = analogRead(X_AXIS_PIN);
  uint16_t poti_2 = analogRead(Y_AXIS_PIN);
  
  float voltage_1 = poti_1*5.0/1023.0;
  float voltage_2 = poti_2*5.0/1023.0;

  // Servo 
  uint8_t pos = map(poti_1, 0, 1023, 0, 180);
  servo.write(pos);

  // LCD output
	lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CH1:");
  lcd.print(voltage_1, 3);
  lcd.print("V");

  lcd.setCursor(0,1);
  lcd.print("CH2:");
  lcd.print(voltage_2, 3);
  lcd.print("V");

  // Serial output
  Serial.print(voltage_1);
  Serial.print("V ");
  Serial.print(voltage_2);
  Serial.print("V ");
  Serial.println(botton ? 0 : 1);
}
