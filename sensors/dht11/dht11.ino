#include "DHT.h"

const int DHT_SENSOR_PIN = 3;

DHT dht(DHT_SENSOR_PIN, DHT11);

void setup(void)
{
    Serial.begin(9600);
    dht.begin();
}

void loop(void)
{
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
  
    Serial.print("T = " );
    Serial.print(temperature, 1);
    Serial.print(" °C; H = " );
    Serial.print(humidity, 1);
    Serial.println("%" );

    delay(2000); // Wait a few seconds between measurements.
}
