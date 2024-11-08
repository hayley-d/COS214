#include "Waiter.h"

void Waiter::writeOrder(std::string& order) {
    this->order = order;
}

void Waiter::sendToKitchen(Kitchen& k) {
    k.addOrder(order);
}

void Waiter::serveCustomer(Customer& c) {
    c.recieveOrder(order);
}
