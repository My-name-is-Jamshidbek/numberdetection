#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include "IWiFiManager.h"

// WiFiManager class implementing IWiFiManager
class WiFiManager : public IWiFiManager {
private:
    const char* ssid;          // SSID for the WiFi network
    const char* password;      // Password for the WiFi network
    IPAddress local_IP;        // Static IP address
    IPAddress gateway;         // Gateway IP address
    IPAddress subnet;          // Subnet mask

public:
    // Constructor to initialize WiFiManager with configuration
    WiFiManager(const char* ssid, const char* password, IPAddress local_IP, IPAddress gateway, IPAddress subnet)
        : ssid(ssid), password(password), local_IP(local_IP), gateway(gateway), subnet(subnet) {}

    // Function to set up WiFi
    void setupWiFi() override {
        if (!WiFi.softAPConfig(local_IP, gateway, subnet)) {
            Serial.println("Failed to configure Static IP");
        }
        WiFi.softAP(ssid, password);
        Serial.print("IP Address: ");
        Serial.println(WiFi.softAPIP());
    }
};

#endif // WIFI_MANAGER_H
