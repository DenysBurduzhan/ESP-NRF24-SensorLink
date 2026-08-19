#include <Arduino.h>
#include "Radio.hpp"
#include "ReceivedData.hpp"

void setup() {

    Serial.begin(9600);

    Serial.println("SimpleRx Starting");
    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.openReadingPipe(1, thisSlaveAddress);
    radio.startListening();
}

void loop() {
    getData();
    showData();
}