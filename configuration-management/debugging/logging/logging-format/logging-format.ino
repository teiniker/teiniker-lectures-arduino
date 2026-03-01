#include <ArduinoLog.h>

void printPrefix(Print* _logOutput, int logLevel) 
{
    switch (logLevel)
    {
        case LOG_LEVEL_SILENT:_logOutput->print("SILENT: " ); break;
        case LOG_LEVEL_FATAL:_logOutput->print("FATAL: "  ); break;
        case LOG_LEVEL_ERROR:_logOutput->print("ERROR: "  ); break;
        case LOG_LEVEL_WARNING:_logOutput->print("WARNING: "); break;
        case LOG_LEVEL_INFO:_logOutput->print("INFO: "   ); break;
        case LOG_LEVEL_TRACE:_logOutput->print("TRACE: "  ); break;
        case LOG_LEVEL_VERBOSE:_logOutput->print("VERBOSE: "); break;
    }   
}

void printSuffix(Print* _logOutput, int logLevel) 
{
  _logOutput->print("\n");
}


void setup() 
{
    Serial.begin(115200);
    //Log.begin(LOG_LEVEL_SILENT, &Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    Log.setPrefix(printPrefix); 
    Log.setSuffix(printSuffix);
    Log.setShowLevel(false);
      
    Log.info("setup() done");
}

uint8_t counter = 0;

void loop() 
{
    Log.verbose("enter loop()");
    Log.trace("counter = %X", counter);
    
    counter++;
    
    delay(1000);
    Log.verbose("exit loop()");
}
