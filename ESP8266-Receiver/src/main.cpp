#include <Arduino.h>
#include "Radio.hpp"
#include "ReceivedData.hpp"
#include "Display.hpp"

#define interval 2000

uint32_t start;

void setup() {

    Serial.begin(9600);

    disp.init();

    Serial.println("SimpleRx Starting");
    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.openReadingPipe(1, thisSlaveAddress);
    radio.startListening();

    start = millis();
    
}

void loop() {
    getData();
    showData();
    showOnDisplay(data.temp, data.hum, start, interval);
}