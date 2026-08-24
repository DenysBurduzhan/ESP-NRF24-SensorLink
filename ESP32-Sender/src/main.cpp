#include <Arduino.h>
#include "Radio.hpp"
#include "SensorData.hpp"
#include "DhtSensor.hpp"

unsigned long currentMillis;
unsigned long prevMillis;
//unsigned long txIntervalMillis = 1000;

QueueHandle_t sensorQueue = NULL;

void SensorTask(void *pvParameters){
    while(1){
        readTemperatureAndHumidity();
        xQueueSend(sensorQueue, &data, portMAX_DELAY);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void RadioTask(void *pvParameters){
    while(1){
        if(xQueueReceive(sensorQueue, &data, portMAX_DELAY) == pdPASS){
            send();
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}

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

    sensorQueue = xQueueCreate(1, sizeof(SensorData));
    if (sensorQueue == NULL) {
        Serial.println("Failed to create sensor queue");
        while (1);
    }

    xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 1, NULL);
    xTaskCreate(RadioTask, "RadioTask", 2048, NULL, 1, NULL);
}

void loop() {
//   currentMillis = millis();
//     if (currentMillis - prevMillis >= txIntervalMillis) {
//         readTemperatureAndHumidity();
//         send();
//         prevMillis = millis();
//     }
}

