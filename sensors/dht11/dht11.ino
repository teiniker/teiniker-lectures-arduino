#include <dht_nonblocking.h>

const int DHT_SENSOR_PIN = 8;

DHT_nonblocking sensor( DHT_SENSOR_PIN, DHT_TYPE_11);

void setup(void)
{
  Serial.begin( 9600);
}

void loop(void)
{
  float temperature;
  float humidity;

  /*
   * Instruct the DHT to begin sampling.  Keep polling until it returns true.
   * The tempearture is in degrees Celsius, and the humidity is in %.
   * (COOLDOWN_TIME  2000ms)
   */
  if(sensor.measure(&temperature, &humidity))
  {   
     Serial.print( "T = " );
     Serial.print( temperature, 1 );
     Serial.print( " deg. C, H = " );
     Serial.print( humidity, 1 );
     Serial.println( "%" );
  }
}
