#pragma once

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 22
#define CSN_PIN 21

extern RF24 radio;

extern const byte slaveAddress[5];

void send();