#ifndef I_WEB_SERVER_H
#define I_WEB_SERVER_H

// Interface for WebServer
class IWebServer {
public:
    // Pure virtual function to set up the web server
    virtual void setupServer() = 0;
};

#endif // I_WEB_SERVER_H
