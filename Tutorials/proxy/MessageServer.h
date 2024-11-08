#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H
#include <string>

class MessageServer {
public:
    virtual ~MessageServer() = default;
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void message(std::string& msg) = 0;
};
#endif //MESSAGESERVER_H
