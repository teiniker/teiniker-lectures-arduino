// Hardware Abstraction
 
class Led
{
    private:
        uint8_t _pin;
        bool _state;

    public:
        Led(uint8_t pin, bool state = false)
        {
            if(pin > 1 && pin < 14)
                _pin = pin;
            else 
                _pin = 13; // on-board LED

            _state = state; 
            pinMode(_pin, OUTPUT); 
        }

        void on(void)
        {
            _state = true;
            _setPin();
        }

        void off(void)
        {
            _state = false;
            _setPin();
        }        

        void toggle(void)
        {
            _state = !_state;
            _setPin();
        }        

    private: 
        void _setPin()
        {
            digitalWrite(_pin, _state);
        }

};

// Application 

Led led(13);

void setup() 
{
}

void loop() 
{
  led.toggle();  
  delay(1000);                       
}
