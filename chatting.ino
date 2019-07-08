#include <Esplora.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(D5, D6); // RX, TX

void setup() {

pinMode(D0,OUTPUT);

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() { // run over and over
//  void loop() { // run over and over
  if (mySerial.available()) {
    //receive Serial
    //Serial.write(mySerial.read());
    
    char command = mySerial.read();
    Serial.print(command);
    if(command == 'a') {
//      case  'a' :
        digitalWrite(D0, LOW);
        mySerial.print("LED ON\n"); }        
//        break;  
    if(command == 'b') {
//      case  'b' :
        digitalWrite(D0, HIGH);
        mySerial.print("LED OFF\n");
//        break;
    }
  }
  if (Serial.available()) {
    //send Serial
    char BB= Serial.read();
    Serial.print(BB);
    mySerial.print(BB);
//    mySerial.write(Serial.read());
  }
}
