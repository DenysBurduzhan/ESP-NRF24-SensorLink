#include "Display.hpp"

TM1637 disp(CLK_PIN, DIO_PIN);

void showOnDisplay(float temperature, float humidity, uint32_t& start, uint32_t interval) {
uint32_t currentMillis = millis();
static bool showTemp = false;
    if (currentMillis - start >= interval) {
        start = currentMillis;
        showTemp = !showTemp;
    }

    if (showTemp) {
        int temp = (int)temperature;
        disp.display(String(temp) + "C");
    }
    else {
        int hum = (int)humidity;
        disp.display(String(hum) + "h");
    }
}