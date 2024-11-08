#ifndef REALMESSAGESERVER_H
#define REALMESSAGESERVER_H
#include "MessageServer.h"
#include <string>

class RealMessageServer : public MessageServer{
public:
    RealMessageServer();
    ~RealMessageServer() = default; 
    void connect() override;
    void disconnect() override;
    void message(std::string& msg) override;
};
#endif //REALMESSAGESERVER_H
