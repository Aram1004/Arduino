void setup() {

  pinMode(D1, OUTPUT); // 빨강 R   //pinMode 3개 
  pinMode(D2, OUTPUT); // 초록 G
  pinMode(D3, OUTPUT); // 파랑 B
Serial.begin(9600);
}

void loop() {
 int Adc = analogRead(A0);
 Serial.print("Adc=");
 Serial.println(Adc);
 delay(300);
 
 if(0<Adc and Adc<300){
digitalWrite(D1, 1);
delay(500);
digitalWrite(D1, 0);
delay(500);
 }
if(301<Adc && Adc<600){
digitalWrite(D2, 1);
delay(500);
digitalWrite(D2, 0);
delay(500);
}
if (Adc > 600 && Adc<1024){
digitalWrite(D3, 1);
delay(500);
digitalWrite(D3, 0);
delay(500);
}
//  if (Adc > 500){
//  digitalWrite(D1, 1);
//  }
//  else{
//  digitalWrite(D1, 0);

  }
