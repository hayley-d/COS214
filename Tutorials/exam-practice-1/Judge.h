#ifndef JUDGE_H
#define JUDGE_H

#include <string>
#include "User.h"

class Judge : public User {
public:
    Judge(std::string username,std::string password) : User(username,password) {}
    ~Judge() = default;
};
#endif //JUDGE_H
