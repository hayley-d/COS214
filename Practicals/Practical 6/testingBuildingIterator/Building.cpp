// DO NOT SUBMIT JUST FOR TESTING PURPOSES
#include "Building.h"

Building::Building(int cost, std::shared_ptr<TaxAuthority> taxAuth) : cost(cost), taxAuth(taxAuth){
    std::cout << "Created new building\n";
}

std::string Building::getDetails(){
    return " ";
}

void Building::payTax(int amount) {

}

int Building::getCost() {
    return this->cost;
}
