/*
 * Digital Input with internal Pull-Up (Taster + LED)
 *
 * Pin 9: ---[470]--|>|--(GND)
 *
 * Pin 4: ---o\o--------(GND)
 *
 * The internal pull-up resistor keeps Pin 4 HIGH while the
 * button is open. Pressing the button pulls Pin 4 to LOW.
 */

const int LED_PIN    = 9;
const int TASTER_PIN = 4;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(TASTER_PIN, INPUT_PULLUP);
}

void loop()
{
    int state = digitalRead(TASTER_PIN);

    if(state == LOW)                    // button pressed (active low)
      digitalWrite(LED_PIN, HIGH);
    else
      digitalWrite(LED_PIN, LOW);
}
