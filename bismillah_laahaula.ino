byte LDR = A0;  //cahaya
int nilai;  //cahaya
#include "DHT.h"  //suhu->
#define DHTPIN A1
#define DHTTYPE DHT11 //menggunakan hardware sensor DHT11
DHT dht(DHTPIN, DHTTYPE); //suhu<-
int rain_pin = A2;  //rain->
int output_value; //rain<-
int moisture_pin = A3;  //moisture->
int output_moisture ;

void setup(){
  Serial.begin(9600);
  Serial.println("JUM'AT LEGI");
  delay(5000);
  dht.begin();  //suhu
}

void loop(){
  nilai = analogRead (LDR); 
  Serial.println("Nilai LDR TERBACA : ");
  delay(2000);
  Serial.println (nilai); //cahaya->
  if (nilai <100){
    Serial.println("CUACA CERAH COK!"); //cahaya<-
    float humidity = dht.readHumidity();  //suhu->
    float celcius = dht.readTemperature();
      if (isnan(humidity) || isnan(celcius)) {
         Serial.println("SENSOR SUHU RUSAK COK!"); //kemungkinan ada yang rusak
         return;
      }else{
        Serial.print("Humidity : ");  //kelembaban
        Serial.print(humidity);
        Serial.print(" %t");
        Serial.print("Temperatur : ");
        Serial.print(celcius);
        Serial.println(" C");
        output_value = analogRead(rain_pin);  //hujan->
        Serial.print("Nilai Analog: ");
        Serial.println(output_value);
        int output_value2 = map(output_value,1023,0,0,100);
        Serial.print("Intensitas Hujan : ");
        Serial.print(output_value2);
        Serial.println("%");
        delay(2000);
          if(output_value <= 500){
            Serial.println("ATAP TUTUP COK!");
            delay(5000);
          }else{
            /*Serial.println("ATAP BUKA COK!");
            delay(2000);*/
            output_moisture = analogRead(moisture_pin);  //moisture->
            Serial.print("Nilai Analog: ");
            Serial.println(output_moisture);
            int output_moisture2 = map(output_moisture,1023,0,0,100);
            Serial.print("Presentase Kelembapan Objek : ");
            Serial.print(output_moisture2);
            Serial.println("%");
            delay(2000);
            if(output_value <= 500){
                Serial.println("ATAP TUTUP COK!");
                delay(5000);
            }else{
                Serial.println("ATAP BUKA COK!");
                delay(2000);
          }//moisture<-
          }//hujan<-
        }//suhu<-
  }else{//cahaya->
    Serial.println("MENDUNG ATAU MALAM COK!"); //cahaya<-
   float humidity = dht.readHumidity();  //suhu->
    float celcius = dht.readTemperature();
      if (isnan(humidity) || isnan(celcius)) {
         Serial.println("SENSOR SUHU RUSAK COK!"); //kemungkinan ada yang rusak
         return;
      }else{
        Serial.print("Humidity : ");  //kelembaban
        Serial.print(humidity);
        Serial.print(" %t");
        Serial.print("Temperatur : ");
        Serial.print(celcius);
        Serial.println(" C");
        }
      }//suhu<-
  }//cahaya<-
