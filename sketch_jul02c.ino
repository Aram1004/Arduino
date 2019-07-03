// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = D1;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(D0, OUTPUT);
}

unsigned long prev_time = 0;

void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  if(buttonState == HIGH) {
    digitalWrite(D0,HIGH);
    delay(2000);
    digitalWrite(D0,HIGH);
    delay(2000);
  }
  
  unsigned long current_time = millis();
  
  // if 1 second has passed after last check
  if(current_time - prev_time > 1000) {
    // print out the state of the button:
    Serial.println("hahaha");
    prev_time = current_time;
  }
  
  delay(1);        // delay in between reads for stability
}
