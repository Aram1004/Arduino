
#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "SEOUL_PUBLIC_GONGDEOK"
#define STAPSK  ""
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);
float t =20.3;

void setup() {
  Serial.begin(115200);

  // prepare LED
  pinMode(D0, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);  //ssid출력

  WiFi.mode(WIFI_STA);  //nodemcu 1.ap 모드(내가 내 pi줌) 2.STA mode내가 다른 pi에 붙겠다
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {  //WIFI가 연결되지 않았을때
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Start the server
  server.begin();
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());  //클라이언트가 나에게 붙는지 확인 (서버의 IP 주소)
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();  //클라이언트가 붙엇는지 확인   동작특성:계속해서 물어보는것 EVENT:어떤 이벤트가 발생했을때 확인하는것
  if (!client) {
    return;
  }
  Serial.println(F("new client"));

  client.setTimeout(5000); // default is 1000

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

  // Match the request
  int val;
  if (req.indexOf(F("/1")) != -1) {  //내가 보내는것
    val = 0;
  } else if (req.indexOf(F("/0")) != -1) {
    val = 1;
  } else {
    Serial.println(F("invalid request"));
    val = digitalRead(D0); // 현재상태를 체크하기 위해서 
  }

  // Set LED according to the request
  digitalWrite(D0, val);

  // read/ignore the rest of the request
  // do not client.flush(): it is for output only, see below
  while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }

  // Send the response to the client
  // it is OK for multiple small client.print/write,
  // because nagle algorithm will group them into one single packet
  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nTemp is : ")); //형식이 중요!!
  client.print(t);
  client.print((val) ? F("high") : F("low"));
  client.print(F("<br><br>Click <a href='http://"));  //클릭만 하면 자동으로 온오프 되도록 서버로 연결!!
  client.print(WiFi.localIP());
  client.print(F("/1'>here</a> to switch LED GPIO on, or <a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/0'>here</a> to switch LED GPIO off.</html>"));

  // The client will actually be *flushed* then disconnected
  // when the function returns and 'client' object is destroyed (out-of-scope)
  // flush = ensure written data are received by the other side
  Serial.println(F("Disconnecting from client"));
}
// 로컬 IP : 172.30.36.29
