# ESP32 Setup with Arduino IDE

## Step 1: Install Arduino IDE

Download the latest Arduino IDE from:
            
            https://www.arduino.cc/en/software

## Step 2: Install ESP32 Board Support

Open Arduino IDE → File → Preferences.

In the Additional Board Manager URLs field, paste:
                
            https://dl.espressif.com/dl/package_esp32_index.json

(If there are already entries, add a comma and paste this link.)

Click OK.

Now go to Tools → Board → Board Manager.

            Search for ESP32 and install ESP32 by Espressif Systems. 


## Step 3: Connect ESP32 to Your PC

Use a micro-USB cable (ensure it supports data transfer, not just charging).

In Arduino IDE → Tools → Port, select the COM port that appears when you plug in your ESP32.

Board Selection:
Tools → Board → ESP32 Arduino → ESP32 Dev Module

## Step 4: Test with "Blink" Sketch
Paste this code into Arduino IDE:

            void setup() {
            pinMode(2, OUTPUT);  // LED on GPIO 2
            }

            void loop() {
            digitalWrite(2, HIGH);   // turn the LED on
            delay(1000);             // wait 1 second
            digitalWrite(2, LOW);    // turn the LED off
            delay(1000);             // wait 1 second
            }

Now click Verify → Upload.

If it uploads successfully, the onboard LED should blink. 

## Step 5: Connect ESP32 to Wi-Fi
Try this Wi-Fi test code:


            #include <WiFi.h>

            const char* ssid     = "YOUR_WIFI_NAME";
            const char* password = "YOUR_WIFI_PASSWORD";

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

Then open Tools → Serial Monitor, set baud rate to 115200,
and you should see "Connected!" followed by your ESP32’s local IP address.
