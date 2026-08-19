#include "Radio.hpp"
#include "ReceivedData.hpp"

const byte thisSlaveAddress[5] = {'R','x','A','A','A'};
RF24 radio(CE_PIN, CSN_PIN);
bool newData = false;


void getData() {
    if ( radio.available() ) {
        radio.read( &data, sizeof(data) );
        newData = true;
    }
}

void showData() {
    if (newData == true) {
        Serial.print("Data received ");
        Serial.println("Humidity: " + String(data.hum) + " Temperature: " + String(data.temp));
        newData = false;
    }
}