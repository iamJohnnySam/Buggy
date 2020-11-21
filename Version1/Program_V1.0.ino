#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

#define M1p 5
#define M1n 4
#define M2p 0
#define M2n 2
#define M3p 14
#define M3n 12
#define M4p 13
#define M4n 15

const char *ssid = "iamJohnnySam-Car";
const char *password = "1234567890";
IPAddress ip(192, 168, 4, 1);
IPAddress netmask(255, 255, 255, 0);
const int port = 8080; // Port
ESP8266WebServer server(port);

int fSpeed = 800;
int tSpeed = 400;

void setup() { 
  setupPins();
  Serial.begin(115200);
  setupWiFi();
  startWebServer();
  Serial.println("done");
}

void loop() {
  server.handleClient();
}
