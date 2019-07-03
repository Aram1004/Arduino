void setup() {
  // put your setup code here, to run once:
pinMode(D1,OUTPUT);
Serial.begin(9600);   //통신 속도
}

void loop() {
  char command;
  // put your main code here, to run repeatedly:
if(Serial.available( )>0) {    //Serial은 pc! pc에서 데이터가 왔니?물어보는것
  command = Serial.read();
  if(command =='a'); {
    digitalWrite(D1,HIGH);}
   if(command == 'b');{
    digitalWrite(D1,LOW);}
   }
}
