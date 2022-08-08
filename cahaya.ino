byte LDR = A0;
int nilai;

void setup(){
  Serial.begin(9600);
}

void loop(){
  nilai = analogRead (LDR);
  Serial.println("Nilai LDR TERBACA : ");
  delay(300);
  Serial.println (nilai);
  if (nilai <100){
    Serial.println("ADA CAHAYA");
    delay(500);
  }
    else{
      Serial.println("CAHAYA HILANG");
      delay(500);
    }
  }
