#include "Application.h"
#include "WifiConnection.h"

Application::Application() {
    user = nullptr;
    server = new ApplicationServer();
    connection = new WifiConnection();
}

Application::~Application() {
    if(user) {
        delete user;
    }

    if(server) {
        delete server;
    }

    if(connection) {
        delete connection;
    }
}

bool Application::connectToServer() {
    if(user) {
        connection->connect();
        std::cout << "Attempting to connect to server.\n";
        server->connect();
        return true;
    }
    std::cout << "Please authenticate before connecting.\n";
    return false;
}

void Application::changeConnection(Connection& connection) {
    if(connection != nullptr) {
        delete this->connection;
        this->connection = &connection;
        return;
    } 
    this->connection = &connection;
}

bool Application::disconnect() {
    if(user != nullptr && server != nullptr) {
        server->disconnect();
    }
}

bool Application::authenticateUser(User& user) {
    if(this->user == nullptr) {
        if(server->authenticate(user.username,user.password)) {
            this->user = &user;
        };
    }
}

void Application::addReview(std::string review) {
    if(user != nullptr) {
        server->addReview(user->username,review);
    }
}
