void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int Adc= analogRead(A0);
analogWrite(D1,Adc);
Serial.print("Adc = ");
Serial.println(Adc);
analogWrite(D1,Adc);
}
