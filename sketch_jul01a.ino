void setup() {
 pinMode(D0, OUTPUT);  //발광다이오드
 pinMode(D1, INPUT);   //3.3볼트 전하가 들어오는 input
 Serial.begin(9600); // 9600의 속도로 시리얼로 데이터가 오는 것을 pc에 알려줘   .점: 객체, 클래스,오브젝트를 선언한 것!!(시리얼을 준비하라)

}

void loop() {
 //조건이 생성해주기  -만약에 D1눌러지면 high가 되면 불이켜지고 손을 떼면 불이 꺼지게 구현
  int SW =digitalRead(D1); // 디지털 1핀의 값을 읽어서 SW라는 변수에 저장해라
  delay(100);
  if(SW>0){ digitalWrite(D0,HIGH); Serial.println(SW);} //SW 의 값을 출력해봐라  //high랑 1이랑 똑같음
  else    {digitalWrite(D0,LOW);Serial.println(SW);}
}
