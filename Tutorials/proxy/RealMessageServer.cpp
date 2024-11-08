#include "RealMessageServer.h"
#include <iostream>
#include <string>

void RealMessageServer::connect() {
    std::cout << "Connecting...\n";
}

void RealMessageServer::disconnect() {
    std::cout << "Disconnecting.\n";
}

void RealMessageServer::message(std::string& msg) {
    std::cout << msg;
}

