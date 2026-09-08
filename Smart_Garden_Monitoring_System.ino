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

  delay(2000); // Increase delay to 2 seconds
} 
