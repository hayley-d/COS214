#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    std::string username;
    std::string password;

    User(std::string username,std::string password) : username(username), password(password) {}
    virtual ~User() = default;
};
#endif //USER_H
