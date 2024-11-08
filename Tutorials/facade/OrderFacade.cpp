#include "OrderFacade.h"

OrderFacade::OrderFacade() {
    waiter = new Waiter(0);
    kitchen = new Kitchen();
    customer = new Customer();
}

OrderFacade::~OrderFacade() {
    delete waiter;
    delete kitchen;
    delete customer;
}

void OrderFacade::order_food() {
    std::string order = "Carrot Cake"; 
    waiter->writeOrder(order);
    waiter->sendToKitchen(*kitchen);
    waiter->serveCustomer(*customer);
}
