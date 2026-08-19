#include "Radio.hpp"
#include "SensorData.hpp"

const byte slaveAddress[5] = {'R','x','A','A','A'};

RF24 radio(CE_PIN, CSN_PIN);

void send() {
    bool res = radio.write( &data, sizeof(data) );
    if(res){        
    Serial.println("Data Sent: ");
    Serial.println("Humidity: " + String(data.hum) + " Temperature: " + String(data.temp));
    }else{
        Serial.println("  Fail");
        return;
    }
}