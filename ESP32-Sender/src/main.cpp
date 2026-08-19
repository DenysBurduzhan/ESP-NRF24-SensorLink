#include <Arduino.h>
#include "Radio.hpp"
#include "SensorData.hpp"
#include "DhtSensor.hpp"

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000;

void setup() {
  Serial.begin(9600);
    dht.begin();
    Serial.println("SimpleTx Starting");

    radio.begin();
    if(!radio.begin())
{
    Serial.println("NRF24 not found!");
    while(1);
}
    radio.setDataRate( RF24_250KBPS );
    radio.setRetries(3,5);
    radio.openWritingPipe(slaveAddress);
    radio.stopListening();
}

void loop() {
  currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
        readTemperatureAndHumidity();
        send();
        prevMillis = millis();
    }
}

