#include "DHT.h"

#define DHTPIN   5
#define DHTTYPE  DHT11

DHT dht(DHTPIN, DHTTYPE);

void readTemperatureAndHumidity();
  