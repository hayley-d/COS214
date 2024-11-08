#ifndef PROXYMESSAGESERVER_H
#define PROXYMESSAGESERVER_H
#include "MessageServer.h"
#include "RealMessageServer.h"

class ProxyMessageServer : public MessageServer {
    RealMessageServer* real_msg_server;
    bool registered;
    bool connected;
public:
    ProxyMessageServer();
    ~ProxyMessageServer() {
        if(real_msg_server) {
            delete real_msg_server;
        }
    }
    void connect() override;
    void disconnect() override;
    void message(std::string& msg) override;

};
#endif //PROXYMESSAGESERVER_H
