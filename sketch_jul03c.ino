//삼색led
void setup() {
  // put your setup code here, to run once:
pinMode(D0,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char Input;
  if(Serial.available()) {
  Input = Serial.read();
  switch(INPUT){
  case'A':
  digitalWrite(D0,HIGH);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  Serial.println("A");
  break;
  case'B':
  digitalWrite(D0,LOW);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);
  break;
  
  case 'C':
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  break;

  case 'D':
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  break;
  }
  }
}
