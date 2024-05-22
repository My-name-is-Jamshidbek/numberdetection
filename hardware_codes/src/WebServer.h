#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include "IStepperController.h"
#include "IWebServer.h"

class WebServer : public IWebServer {
private:
    AsyncWebServer server;
    IStepperController& stepperController;

    void notFound(AsyncWebServerRequest* request) {
        request->send(404, "text/plain", "Not found");
    }

public:
    WebServer(IStepperController& stepperController)
        : server(80), stepperController(stepperController) {}

    void setupServer() override {
        server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
            request->send(200, "text/plain", "Hello, world");
        });

        server.on("/servo", HTTP_GET, [this](AsyncWebServerRequest* request) {
            if (request->hasParam("angle")) {
                int angle = request->getParam("angle")->value().toInt();
                Serial.println("Servo: " + String(angle));
                this->stepperController.moveToAngle(angle);
            }
            request->send(200, "text/plain", "Servo moved");
        });

        server.onNotFound([this](AsyncWebServerRequest* request) { this->notFound(request); });

        server.begin();
    }
};

#endif // WEB_SERVER_H