void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Adc = analogRead(A0);
float mv = (Adc/1023.0)*3000;  //3.3V= 3300mv
//(3.3 * analogRead(A0) * 100.0) / 1024;
float Temp = mv / 10;
Serial.print("Temp = ");
Serial.print(Temp,1);
Serial.println("[C]");
delay(300);

}
