#include "Radio.hpp"
#include "SensorData.hpp"

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