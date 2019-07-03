#include <Wire.h> 
#include <DHT.h>

#include <LiquidCrystal_I2C.h>  // I2C를 사용하기위한 라이브러리 불러옴

#define DHTPIN D3     // Digital pin connected to the DHT sensor  D2핀에 설정함
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE); //객체선언


// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  
	// initialize the LCD
	lcd.begin();
  Serial.begin(9600);
	// Turn on the blacklight and print a message.
	lcd.backlight();
 
  dht.begin();
  pinMode(D1,OUTPUT);
//	lcd.print("Hello, world!");
//  delay(3000);
//  lcd.clear();  //글자 지우기
}

void loop()
{ 
//  lcd.clear();
//  lcd.setCursor(0,0);    // (첫번째 칸, 첫째줄)
//  lcd.print("Hello, world!");// (칸, 줄)
//  delay(100);
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print("12345");
//  delay(100);
//  lcd.clear();
  float Temp= dht.readTemperature();
  float Hum= dht.readHumidity();
  Serial.println(Temp,1);
  lcd.setCursor(0,0); 
  lcd.print("Temp = ");
  lcd.print(Temp);
  lcd.println("[C]");

  Serial.println(Hum,1);
  lcd.setCursor(0,1); 
  lcd.print("Hum= ");
  lcd.print(Hum);
  lcd.print("%");
  if (Temp>28){digitalWrite(D0,LOW);}
  else {digitalWrite(D0,HIGH);}
  
  
	// Do nothing here...
}
