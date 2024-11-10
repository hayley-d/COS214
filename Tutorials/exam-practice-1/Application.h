#ifndef APPLICATION_H
#define APPLICATION_H
#include "User.h"
#include "Connection.h"
#include "ApplicationServer.h"


class Application {
private:
    ApplicationServer* server;
    User* user;
    Connection* connection;

public:
    Application();
    ~Application();
    bool connectToServer();
    void changeConnection(Connection& connection);
    bool disconnect();
    bool authenticateUser(User& user);
    void addReview(std::string review);
};
#endif //APPLICATION_H
