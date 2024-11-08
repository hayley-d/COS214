#include "ProxyMessageServer.h"

ProxyMessageServer::ProxyMessageServer() {
    real_msg_server = new RealMessageServer();
    registered = true;
    connected = false;
}

void ProxyMessageServer::connect() {
    if(registered && !connected) {
        real_msg_server->connect();
        connected = true;
    }
}

void ProxyMessageServer::disconnect() {
    if(registered && connected) {
        real_msg_server->disconnect();
        connected = false;
    }
}

void ProxyMessageServer::message(std::string& msg) {
    if(registered && connected) {
        real_msg_server->message(msg);
    }
}

