#include <Wire.h> 
 
#define LIMIT_LDR 200 // nilai batas intensitas cahaya pada LDR
#define LIMIT_RAIN 850 // nilai batas air pada sensor
#define LIMIT_MOISTURE 1000 //nilai batas kadar air pada objek
#define LIMIT_MOTOR 75 // nilai batas waktu putaran motor
#define LIMIT_SPEED 200 // nilai kecepatan motor
 
byte hold1 = 0; // tahan putaran motor jemur
byte hold2 = 0; // tahan putaran motor balik
byte Stop = 0;
 
const byte en1 = 4;
const byte en2 = 5;
const byte speedMotor = 9; 
 
void jemur();
void kembali();
void berhenti();
 
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP); // set sebagai output
  pinMode(A1, INPUT_PULLUP); // set sebagai output
  pinMode(A2, INPUT_PULLUP); // set sebagai output
  Serial.println("Jemuran Otomatis");
  delay(2000);
}
 
void loop()
{
  int s_ldr = analogRead(A0);
  int s_rain = analogRead(A1);
  int s_moisture = analogRead(A2);
 if ( s_ldr < LIMIT_LDR && s_rain > LIMIT_RAIN && s_moisture < LIMIT_MOISTURE){ // TERANG ATAU TIDAK HUJAN
  
    Serial.println("Buka Atap!");
     if ( hold1 == 0){
        Serial.println("Motor Jalan");
        jemur(); 
     }
     if ( Stop == 1){
        Serial.println("Motor Stop");
     }
      
  }
  if ( s_ldr > LIMIT_LDR || s_rain < LIMIT_RAIN || s_moisture >  LIMIT_MOISTURE){ // GELAP ATAU HUJAN
    Serial.println("Tutup Atap!");
    Serial.print(s_rain);
    delay(1000);
    if ( hold2 == 0){
        Serial.println("Motor Jalan");
        kembali(); 
     }
     if ( Stop == 1){
        Serial.println("Motor Stop");
     }
  }
 
  delay(250);
   
}
 
 
void jemur(){
  Stop = 0;
  for ( int i = 0; i < LIMIT_MOTOR; i++){
    analogWrite(speedMotor, LIMIT_SPEED);
    digitalWrite(en1, LOW);
    digitalWrite(en2, HIGH);
    delay(55);
    if ( i == LIMIT_MOTOR - 1){
      hold1 = 1;
      hold2 = 0;
      berhenti();
    }
  }
}
 
void kembali(){
  Stop = 0;
   for ( int i = 0; i < LIMIT_MOTOR; i++){
    analogWrite(speedMotor, LIMIT_SPEED);
    digitalWrite(en1, HIGH);
    digitalWrite(en2, LOW);
    delay(50);
     if ( i == LIMIT_MOTOR - 1){
      hold1 = 0;
      hold2 = 1;
      berhenti();
    }


    
  }
}
 
void berhenti(){
    analogWrite(speedMotor, 0);
    digitalWrite(en1, LOW);
    digitalWrite(en2, HIGH);
    Stop = 1;
    delay(100);
}
