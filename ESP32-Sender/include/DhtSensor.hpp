#pragma once

#include "DHT.h"

#define DHTPIN   5
#define DHTTYPE  DHT11

extern DHT dht;

void readTemperatureAndHumidity();
  