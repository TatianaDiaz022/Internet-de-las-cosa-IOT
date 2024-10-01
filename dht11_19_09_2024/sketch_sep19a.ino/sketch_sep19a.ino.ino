/*
Data : 19-09-2024
Developer: Tatiana D
Sketch descrition: Get temperature and humidity from DHT11 Sensor
*/
#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 5

float temp = 0;
float hum = 0;
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  
  dht.begin();
  Serial.begin(9600);

}

void loop() {

  delay(1000);
  
  temp = dht.readTemperature();
  hum =dht.readHumidity();

  Serial.println(temp);
  Serial.println(hum);

}
