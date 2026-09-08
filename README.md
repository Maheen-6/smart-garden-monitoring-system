# Smart Garden Monitoring System

## Description

The Smart Garden Monitoring System is an Arduino-based system that monitors temperature, humidity, and soil moisture. The sensor readings are displayed on a 128×64 OLED display and also printed on the Serial Monitor.

## Components

* Arduino UNO
* DHT11 Temperature and Humidity Sensor
* Soil Moisture Sensor
* 128×64 SSD1306 OLED Display

## Pin Connections

| Component            | Arduino Pin |
| -------------------- | ----------- |
| DHT11 Data           | D2          |
| Soil Moisture Sensor | A0          |
| OLED SDA             | A4          |
| OLED SCL             | A5          |

## Features

* Temperature measurement using DHT11
* Humidity measurement using DHT11
* Soil moisture measurement
* Real-time OLED display
* Serial Monitor output
* Sensor readings updated every 2 seconds

## Libraries Used

* U8g2lib
* DHT

## How It Works

The DHT11 sensor measures temperature and humidity, while the soil moisture sensor reads the soil moisture level through analog pin A0. The Arduino UNO processes these readings and displays them on the OLED screen. The same readings are also sent to the Serial Monitor.

The system updates the readings every 2 seconds.

## Output

The OLED displays:

* Temperature
* Humidity
* Soil Moisture

The Serial Monitor also displays the temperature, humidity, and soil moisture readings.

## Arduino Code

```cpp
#include <U8g2lib.h>
#include <DHT.h>

#define OLED_SDA A4
#define OLED_SCL A5
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, OLED_SCL, OLED_SDA);

void setup() {
  Serial.begin(9600);
  dht.begin();
  u8g2.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soilMoisture = analogRead(A0);

  // Display on OLED
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setCursor(0, 15);
  u8g2.print("Temp: ");
  u8g2.print(temperature);
  u8g2.print("C, Humidity: ");
  u8g2.print(humidity);
  u8g2.setCursor(0, 30);
  u8g2.print("Soil Moisture: ");
  u8g2.print(soilMoisture);
  u8g2.sendBuffer();

  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Soil Moisture: ");
  Serial.print(soilMoisture);
  Serial.println();

  delay(2000);
}
```
