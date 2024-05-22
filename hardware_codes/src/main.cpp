#include <Arduino.h>
#include "WiFiManager.h"

// WiFi configuration
const char* ssid = "test";
const char* password = "c1tr0nR&D";
IPAddress local_IP(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// Create WiFiManager instance
WiFiManager wifiManager(ssid, password, local_IP, gateway, subnet);

void setup() {
  Serial.begin(115200);

  // Setup WiFi
  wifiManager.setupWiFi();
}

void loop() {
  // Main loop code here
}