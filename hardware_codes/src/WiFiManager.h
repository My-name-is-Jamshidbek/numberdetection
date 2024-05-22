#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include "IWiFiManager.h"

class WiFiManager : public IWiFiManager {
private:
    const char* ssid;
    const char* password;
    IPAddress local_IP;
    IPAddress gateway;
    IPAddress subnet;

public:
    WiFiManager(const char* ssid, const char* password, IPAddress local_IP, IPAddress gateway, IPAddress subnet)
        : ssid(ssid), password(password), local_IP(local_IP), gateway(gateway), subnet(subnet) {}

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