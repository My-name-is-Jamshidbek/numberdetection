#ifndef I_WEB_SERVER_H
#define I_WEB_SERVER_H

class IWebServer {
public:
    virtual void setupServer() = 0;
};

#endif // I_WEB_SERVER_H