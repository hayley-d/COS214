#ifndef WAITER_H
#define WAITER_h
#include <string>
#include "Kitchen.h"
#include "Customer.h"

class Waiter {
private:
    int id;
    std::string order;

public:
    Waiter(int id) : id(id) {};

    ~Waiter() = default;

    void writeOrder(std::string& order);

    void sendToKitchen(Kitchen& k);

    void serveCustomer(Customer& c);
};

#endif //WAITER_H
