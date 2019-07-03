void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 int Adc = analogRead(A0);  // ㅁ
analogWrite(D1,Adc);  //제일 밝은거 full   // Adc로 밝기를 조절
//delay(500);
//analogWrite(D1,Adc);
//delay(500);
//analogWrite(D1,0);  //pwm이라는 함수로 밝기를 조절할 수 있다.
//delay(500);
//가변저항의 값으로 밝기를 조절

}
