#ifndef WIFICONNECTION_H
#define WIFICONNECTION_H
#include "Connection.h"

class LanConnection : public Connection{
public:
    LanConnection() = default;
    void connect();
    ~LanConnection() = default;
};
#endif //WIFICONNECTION_H
