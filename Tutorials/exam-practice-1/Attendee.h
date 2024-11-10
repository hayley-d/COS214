#ifndef ATTENDEE_H
#define ATTENDEE_H

#include <string>
#include "User.h"

class Attendee : public User {
public:
    Attendee(std::string username,std::string password) : User(username,password) {}
    ~Attendee() = default;
};
#endif //ATTENDEE_H
