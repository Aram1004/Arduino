int trig = D1;
int echo=D2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(D3, OUTPUT);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  // put your main code here, to run repeatedly:
int distance = pulseIn(echo, HIGH)*17/1000;  //echo 가 high가 될떄까지의 시간계산
Serial.print(distance);
Serial.println("cm");

int Time = map(distance, 0, 400, 0, 4000);
digitalWrite(D3,HIGH);
delay(Time);
digitalWrite(D3,LOW);
delay(Time);
}
