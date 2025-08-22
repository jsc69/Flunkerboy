#include <WiFi.h>
//#include <WebServer.h>
//#include <TFT_eSPI.h>
//#include "display_ui.h"
//#include "html.h"

const char* ssid = "FlunkerBoy";
const char* password = "";

//WebServer server(80);
//TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  Serial.println("Hello World");
}
/*
void setup() {
  Serial.begin(115200);
  Serial.println("Starting FlunkerBoy");
  Serial.println("Init TFT");
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  Serial.println("Init Wifi");
  WiFi.softAP(ssid, password);
  server.on("/", []() {
    server.send_P(200, "text/html", flunkerboy_html);
  });
  server.on("/data", []() {
    float val = random(0, 10000) / 100.0;
    int range = random(0, 8);
    int dot = String(val, 4).indexOf('.') + 1;
    String json = "{\"value\":\"" + String(val, 4) + "\",\"dot\":" + String(dot) + ",\"range\":" + String(range) + "}";
    server.send(200, "application/json", json);
  });
  server.begin();
  Serial.println("Init done!");
}
*/
void loop() {
  Serial.println(millis());
  delay(1000);
  /*
  static unsigned long lastUpdate = 0;
  static float val = 0.0;
  if (millis() - lastUpdate > 500) {
    val = random(0, 10000) / 100.0;
    renderDisplay(tft, val);
    lastUpdate = millis();
  }
  server.handleClient();
  */
}