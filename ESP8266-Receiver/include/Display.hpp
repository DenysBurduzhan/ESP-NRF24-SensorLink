#pragma once

#include <TM1637.h>

#define CLK_PIN  2
#define DIO_PIN  0

extern TM1637 disp;

void showOnDisplay(float temperature, float humidity, uint32_t& start, uint32_t interval);