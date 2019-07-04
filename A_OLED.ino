#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//위에 3개는 무조건 있어야함

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     0 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  // put your setup code here, to run once:
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32 (128x32 이놈의 주소!!)
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  display.setTextSize(10);             // Normal 1:1 pixel scale
  display.setTextColor(BLACK,WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.print("a");
  display.display();     //다쓰구 나서 실행!  꼭 넣줘야한당!
}
