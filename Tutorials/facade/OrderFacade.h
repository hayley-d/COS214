#ifndef ORDERFACADE_H
#define ORDERFACADE_H
#include "Waiter.h"
#include "Kitchen.h"
#include "Customer.h"

class OrderFacade {
    Waiter* waiter;
    Kitchen* kitchen;
    Customer* customer;
public:
    OrderFacade();
    ~OrderFacade();
    void order_food();
};
#endif //ORDERFACADE_H
