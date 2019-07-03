
#include <DHT.h>

#define DHTPIN D2     // Digital pin connected to the DHT sensor  D2핀에 설정함
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);  //객체선언

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(D0,OUTPUT);
}

void loop() {
  float Temp= dht.readTemperature();
  float Hum= dht.readHumidity();
  Serial.print("Temp = ");
  Serial.print(Temp);
  Serial.println("[C]");
  Serial.print("Hum= ");
  Serial.print(Hum);
  Serial.print("%");
  if (Temp>28){digitalWrite(D0,LOW);}
  else {digitalWrite(D0,HIGH);}
  
}
