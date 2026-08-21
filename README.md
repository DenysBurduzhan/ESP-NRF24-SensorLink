# ESP-NRF24-SensorLink

A simple wireless sensor monitoring project based on **ESP32**, **ESP8266**, **nRF24L01**, a DHT sensor, and a TM1637 4-digit display.

## Project Overview

The project consists of two devices:

### Transmitter

The transmitter is based on **ESP32**.

It:

- Reads temperature and humidity from a DHT sensor.
- Sends sensor data using an nRF24L01 radio module.

### Receiver

The receiver is based on **ESP8266 NodeMCU**.

It:

- Receives temperature and humidity data using nRF24L01.
- Displays the received values on a TM1637 4-digit display.

The project was created as a practical embedded C++ project to practice microcontrollers, wireless communication, sensors, displays, and modular C++ programming.

## Features

- Temperature measurement
- Humidity measurement
- DHT sensor support
- Wireless communication using nRF24L01
- ESP32 transmitter
- ESP8266 receiver
- TM1637 4-digit display
- Non-blocking timing using `millis()`
- Modular C++ project structure
- Separate header and source files
- PlatformIO

## Hardware

### Transmitter

- ESP32
- DHT11 or DHT22 sensor
- nRF24L01

### Receiver

- ESP8266 NodeMCU
- nRF24L01
- TM1637 4-digit 7-segment display

## Software

- C++
- Arduino Framework
- PlatformIO
- ESP32
- ESP8266
- RF24
- Adafruit DHT Sensor Library
- AKJ7 TM1637 Driver

## Libraries

The project uses the following PlatformIO dependencies:

```ini
lib_deps =
    adafruit/DHT sensor library@^1.4.7
    nrf24/RF24@^1.6.2
    akj7/TM1637 Driver@^2.2.1
```
## How It Works

The ESP32 transmitter reads temperature and humidity from the DHT sensor.

The values are stored in a simple C++ structure:

```cpp
struct SensorData {
    float temp;
    float hum;
};
```

The structure is transmitted using the nRF24L01 module.

The ESP8266 receiver listens for incoming packets, receives the sensor data, and displays the values on the TM1637 display.

The general data flow is:

```
DHT Sensor
    |
    v
ESP32 Transmitter
    |
    v
nRF24L01
    |
    | 2.4 GHz wireless communication
    |
    v
nRF24L01
    |
    v
ESP8266 Receiver
    |
    v
TM1637 Display
```
Timing

The receiver uses millis() for non-blocking timing.

For example:
```
if (currentMillis - start >= interval) {
    start = currentMillis;
}
```
This allows the program to perform periodic actions without using delay().

The main loop can continue running while the required time interval is being measured.

## Display

The receiver uses a TM1637 4-digit 7-segment display.

The display is used to show the received sensor data, such as:
```
Temperature
Humidity
```

The displayed value can be changed periodically using millis().

## Project Structure

A simplified project structure:
```
ESP-NRF24-SensorLink/
|
+-- transmitter/
|   +-- src/
|   +-- include/
|   +-- platformio.ini
|
+-- receiver/
|   +-- src/
|   +-- include/
|   +-- platformio.ini
|
+-- README.md
```
## Getting Started
### 1. Clone the repository
```git clone https://github.com/DenysBurduzhan/ESP-NRF24-SensorLink.git```
### 2. Open the project in PlatformIO

Open the project using Visual Studio Code with PlatformIO or another compatible PlatformIO environment.

### 3. Connect the hardware

Connect the ESP32 transmitter, ESP8266 receiver, DHT sensor, nRF24L01 modules, and TM1637 display according to the pin definitions in the source code.

### 4. Upload the firmware

Upload the transmitter firmware to the ESP32 and the receiver firmware to the ESP8266.

### 5. Start the devices

After both devices are powered on, the ESP32 reads the sensor data and sends it wirelessly to the ESP8266.

The ESP8266 receives the data and displays the temperature and humidity on the TM1637 display.

## What I Practiced

This project was created as a hands-on embedded C++ project.

It helped me practice:

C++
Classes and objects
Structs
References
Header and source files
Modular code organization
Sensor data acquisition
UART / Serial communication
SPI
nRF24L01 wireless communication
DHT sensors
TM1637 displays
millis()
Non-blocking programming
PlatformIO
Embedded debugging
Possible Future Improvements

## Possible improvements for future versions:

Connection status indication
Lost packet detection
Multiple sensor transmitters
Minimum and maximum temperature
Data logging
Battery voltage monitoring
Configurable transmission interval
Buttons or rotary encoder
Wi-Fi support
MQTT support
OLED display

## Technologies
C++
Arduino
ESP32
ESP8266
PlatformIO
nRF24L01
RF24
DHT11 / DHT22
TM1637
SPI
UART

## License

This project is mainly intended for educational and experimental purposes.
