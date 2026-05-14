#include <DHT11.h>

DHT11 dht11(2);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int temperature = dht11.readTemperature();

    if (temperature != DHT11::ERROR_CHECKSUM &&
        temperature != DHT11::ERROR_TIMEOUT)
    {
        Serial.print("Temperature : ");
        Serial.print(temperature);
        Serial.println(" °C");
    }
    else
    {
        Serial.println(DHT11::getErrorString(temperature));
    }
}
