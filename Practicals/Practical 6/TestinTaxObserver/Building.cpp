// DO NOT SUBMIT JUST FOR TESTING PURPOSES
#include "Building.h"

Building::Building(int cost, std::weak_ptr<TaxAuthority> taxAuth) : cost(cost), taxAuth(taxAuth){
}

std::string Building::getDetails(){
    return " ";
}

void Building::payTax(int amount) {
    
}

int Building::getCost() {
    return this->cost;
}

