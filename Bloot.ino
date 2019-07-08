#include <SoftwareSerial.h>

SoftwareSerial mySerial(D5, D6); // RX, TX

void setup() {
 
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
