#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 22
#define CSN_PIN 21

const byte slaveAddress[5] = {'R','x','A','A','A'};


RF24 radio(CE_PIN, CSN_PIN);

void send();