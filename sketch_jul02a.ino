void setup() {
 pinMode(D0, OUTPUT);  //발광다이오드
 pinMode(D2, INPUT);   //3.3볼트 전하가 들어오는 input
 pinMode(D1, OUTPUT);   //3.3볼트 전하가 들어오는 input
}
// Serial.begin(9600); // 9600의 속도로 시리얼로 데이터가 오는 것을 pc에 알려줘   .점: 객체, 클래스,오브젝트를 선언한 것!!(시리얼을 준비하라)

void loop() {
digitalWrite(D0 ,1);
delay(1000);
digitalWrite(D0 ,0);
delay(1000);  
int buttonSate = digitalRead(D2);
digitalWrite(D1,buttonSate);
}
