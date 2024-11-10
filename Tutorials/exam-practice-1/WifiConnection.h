#ifndef WIFICONNECTION_H
#define WIFICONNECTION_H
#include "Connection.h"

class WifiConnection : public Connection{
public:
    WifiConnection() = default;
    void connect();
    ~WifiConnection() = default;
};
#endif //WIFICONNECTION_H
