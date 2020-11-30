#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <WiFiClientSecure.h>

struct APPLICATION {
  char* name = "MycoBot";
};

const char* wifiSSID = "SECRET_SSID";
const char* wifiPassword = "SECRET_PASSWORD";

String httpRequest = "";
String httpRequestLine = "";

WiFiServer server(80);
WiFiClient httpClient;
WiFiClientSecure httpsClient;

void setup() {
  serialInit();
  builtinLEDInit();
  wifiConnect();
}

void loop() {

  httpClient = server.available();
  builtinBlink();

  if (httpClient.connected()) {

    httpRequestLine = "";
    char inputCharacter;

    Serial.println("Client Connected");
    
    while (httpClient.connected() && httpClient.available()) {

      inputCharacter = httpClient.read();
      httpRequest += inputCharacter;      

      if (inputCharacter == '\n') {
          
        if (httpRequestLine.length() == 0) {

          digitalWrite(LED_BUILTIN, HIGH);
          delay(100); 
          httpConnect(httpClient);
          htmlHead(httpClient);
          htmlBody(httpClient, "I'm too weak to put anything good.");
          htmlBody(httpClient, APPLICATION.name);
          htmlTail(httpClient);
          digitalWrite(LED_BUILTIN, LOW);
          break;

        } else {
          
          httpRequestLine = "";

        }

        builtinBlink(18);

      } else if (inputCharacter != '\r') {

        httpRequestLine += inputCharacter;

      } else {
        ;
      }
    }   
  }

  Serial.print(httpRequest);
  httpRequest = "";
  httpClient.stop();    
}

void htmlBody(WiFiClient c, String content) {
  c.println(content);
}

void htmlBody(WiFiClient c, int content) {
  c.println(content);
}

void htmlHead(WiFiClient c) {
  c.println("<!DOCTYPE html><html><head>");
  c.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  c.println("<link rel='icon' href='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAAS0lEQVR42s2SMQ4AIAjE+P+ncSYdasgNXMJgcyIIlVKPIKdvioAXyWBeJmVpqRZKWtj9QWAKZyWll50b8IcL9JUeQF50n28ckyb0ADG8RLwp05YBAAAAAElFTkSuQmCC' type='image/x-png' />");
  c.println("</head><body>");
  c.println("<h1>MycoBot/h1>");
}

void htmlTail(WiFiClient c) {
  c.println("</body></html>");
  c.println();
}

void httpConnect(WiFiClient c) {
  builtinBlink();
  c.println("HTTP/1.1 200 OK");
  c.println("Content-type:text/html");
  c.println("Connection: close");
  c.println();
}

void wifiConnect() {

  Serial.print(wifiSSID);
  Serial.print(": ");

  WiFi.begin(wifiSSID, wifiPassword);

  builtinBlink();

  while (WiFi.status() != WL_CONNECTED)
  {
    builtinBlink(500);
  }

  server.begin();
  delay(9900);

  Serial.println(WiFi.localIP());
}

void builtinBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100); 
  digitalWrite(LED_BUILTIN, LOW);
}

void builtinBlink(int millisecond) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(millisecond); 
  digitalWrite(LED_BUILTIN, LOW);
}

void builtinLEDInit() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void serialInit() {
    Serial.begin(115200);
    Serial.println("\n\n\n\n\n\n\n\n\n\n");
} 