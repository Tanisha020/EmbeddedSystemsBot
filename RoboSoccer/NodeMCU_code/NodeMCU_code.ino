#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
void setup() {
  Serial.begin(115200);
  Serial.println();
  String ssid = "RoboKick";       // your device name
  String pass = "RoboKick@4321";  // your device password
  // make sure that password length is atleast 8 characters
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, pass);
  IPAddress myIP = WiFi.softAPIP();
  Serial.println("");
  Serial.println("*WiFi-AP-Mode*");
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  delay(3000);
  server.begin();
}
void loop() {
}