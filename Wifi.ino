// getting the ip of the nodemuc using a wifi aceess point 
#include <WiFi.h>

const char* ssid     = "YOUR_WIFI_ACEESS_POINT_NAME";
const char* password = "YOUR_WIFI_ACEESS_POINT_PASSWORD";

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected!");
  Serial.println(WiFi.localIP());  // print ESP32 IP
}

void loop(){}
