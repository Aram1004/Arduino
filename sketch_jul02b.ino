int RledPin=D0;
int GledPin=D1;
int pushButtonPin=D2;

void setup() {
  // put your setup code here, to run once:
pinMode(RledPin,OUTPUT);
pinMode(GledPin,OUTPUT);
pinMode(pushButtonPin,INPUT);
attachInterrupt(D2,buttonRead,CHANGE);
serial
}

void loop() {
  // put your main code here, to run repeatedly:

}
