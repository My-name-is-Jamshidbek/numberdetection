#ifndef I_WIFI_MANAGER_H
#define I_WIFI_MANAGER_H

// Interface for WiFiManager
class IWiFiManager {
public:
    // Pure virtual function to set up WiFi
    virtual void setupWiFi() = 0;
};

#endif // I_WIFI_MANAGER_H
