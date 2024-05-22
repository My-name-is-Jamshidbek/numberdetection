#include <Arduino.h>
#include "WiFiManager.h"
#include "StepperController.h"

// WiFi configuration
const char* ssid = "test";
const char* password = "c1tr0nR&D";
IPAddress local_IP(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// Create WiFiManager instance
WiFiManager wifiManager(ssid, password, local_IP, gateway, subnet);

// Stepper configuration
GStepper2<STEPPER4WIRE> stepper(2038, 5, 4, 0, 2);
StepperController stepperController(stepper);

void setup() {
  Serial.begin(115200);

  // Setup WiFi
  wifiManager.setupWiFi();

  // Setup Stepper (initial setup already done in the constructor of StepperController)
}

void loop() {
  // Main loop code
  stepperController.tick();
}