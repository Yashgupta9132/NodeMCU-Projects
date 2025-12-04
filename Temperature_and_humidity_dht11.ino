// + is vcc 
// - is gnd 
// out is our pin of choice 

#include "DHTesp.h"
DHTesp dht;

void setup() {
  Serial.begin(115200);
  dht.setup(14, DHTesp::DHT11);
}

void loop() {
  TempAndHumidity data = dht.getTempAndHumidity();

  Serial.print("Temp: ");
  Serial.print(data.temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(data.humidity);
  Serial.println(" %");

  delay(2000);
}
