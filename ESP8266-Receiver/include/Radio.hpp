#pragma once
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 5
#define CSN_PIN 4

extern const byte thisSlaveAddress[5];
extern RF24 radio;

void getData();
void showData();