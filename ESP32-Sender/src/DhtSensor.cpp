#include "DhtSensor.hpp"
#include "SensorData.hpp"

void readTemperatureAndHumidity() {
    data.temp = dht.readTemperature();
    data.hum = dht.readHumidity();
    if (isnan(data.hum) || isnan(data.temp))
    {
        Serial.println("Error reading from DHT");
        return;
    }
}