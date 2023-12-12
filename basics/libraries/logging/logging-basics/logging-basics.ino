#include <ArduinoLog.h>

void setup() 
{
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_SILENT, &Serial);
    //Log.begin(LOG_LEVEL_INFO, &Serial);
    //Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    Log.setShowLevel(false);
      
    Log.infoln("setup() done");
}

uint8_t counter = 0;

void loop() 
{
    Log.verbose("enter loop()\n");
    Log.info("counter = %X\n", counter);
    
    counter++;
    
    delay(1000);
    Log.verbose("exit loop()\n");
}
