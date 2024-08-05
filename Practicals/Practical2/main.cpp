#include <iostream>
#include "Boatman.h"
#include "BoatmanFactory.h"
#include "Infantry.h"
#include "InfantryFactory.h"
#include "ShieldBearer.h"
#include "ShieldBearerFactory.h"
#include "CareTaker.h"
#include "ConcreteMemento.h"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

int main() {
    std::cout << "Test 1: Factory Pattern" << std::endl;
    std::cout << "-----------------------" << std::endl;

    std::cout << "Test 1.1: Infantry Factory Test:" << std::endl;
    int passed = 0;
    int total = 0;

    //test constructor
    auto* soldiers_factory = new InfantryFactory();

    ++total;
    if(soldiers_factory->calculateTotalHealthPerUnit() == (50*8)) {
        ++passed;
        std::cout << GREEN << "\tTest 1.1.1 Passed" << RESET << std::endl;
    }else {
        std::cout << RED << "\tTest 1.1.1 Failed" << RESET << std::endl;
    }

    ++total;
    if(soldiers_factory->calculateTotalDamagePerUnit() == (40*8)) {
        ++passed;
        std::cout << GREEN << "\tTest 1.1.2 Passed" << RESET << std::endl;
    }else {
        std::cout << RED << "\tTest 1.1.2 Failed" << RESET << std::endl;
    }

    ++total;
    if(soldiers_factory->calculateTotalDefencePerUnit() == (20*8)) {
        ++passed;
        std::cout << GREEN << "\tTest 1.1.3 Passed" << RESET << std::endl;
    }else {
        std::cout << RED << "\tTest 1.1.3 Failed" << RESET << std::endl;
    }

    ++total;
    Infantry* infantry_unit = dynamic_cast<Infantry *>(soldiers_factory->createUnit());
    if(infantry_unit != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest 1.1.4 Passed" << RESET << std::endl;
    }
    else {
        std::cout << RED << "\tTest 1.1.4 Failed" << RESET << std::endl;
    }

    if(total == passed) {
        std::cout << GREEN << "Passed "<< passed << "/" << total << "\n" << RESET << std::endl;
    }else {
        std::cout << RED << "Failed "<< passed << "/" << total << "\n" << RESET << std::endl;
    }

    delete soldiers_factory;
    delete infantry_unit;

    return 0;
}
