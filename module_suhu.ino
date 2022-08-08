#include "DHT.h"
#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  Serial.println("test module");
  dht.begin();
}
 
void loop() {
  delay(2000);
  float humidity_1 = dht.readHumidity();
  float celcius_1 = dht.readTemperature();
  //float fahrenheit_1 = dht.readTemperature(true);
  if (isnan(humidity_1) || isnan(celcius_1) /*|| isnan(fahrenheit_1)*/) {
    Serial.println("module tidak terbaca"); //kemungkinan ada yang rusak
    return;
  }
 
  //float htof = dht.computeHeatIndex(fahrenheit_1, humidity_1); 
  float htoc = dht.computeHeatIndex(celcius_1, humidity_1, false);
  /*Serial.print(" SUHU 2 : ");
  Serial.print(htof); 
  Serial.println(" 'F");*/
  Serial.print(" SUHU 1 : ");
  Serial.print(htoc);
  Serial.print(" 'C ");
 
}
