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

    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }

    std::cout << "\nTest 2: Prototype Pattern" << std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout << "Test 2.1: Cloning Infantry:" << std::endl;
    passed = 0;
    total = 0;

    // Test Infantry cloning
    ++total;
    Infantry* cloned_infantry = dynamic_cast<Infantry*>(infantry_unit->clonis());
    if (cloned_infantry != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest 2.1.1 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 2.1.1 Failed" << RESET << std::endl;
    }

    std::cout << "Test 2.2: Cloning ShieldBearer:" << std::endl;

    // Test ShieldBearer cloning
    auto* shieldbearer = new ShieldBearer();
    ++total;
    ShieldBearer* cloned_shieldbearer = dynamic_cast<ShieldBearer*>(shieldbearer->clonis());
    if (cloned_shieldbearer != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest 2.2.1 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 2.2.1 Failed" << RESET << std::endl;
    }

    std::cout << "Test 2.3: Cloning Boatman:" << std::endl;

    // Test Boatman cloning
    auto* boatman = new Boatman();
    ++total;
    Boatman* cloned_boatman = dynamic_cast<Boatman*>(boatman->clonis());
    if (cloned_boatman != nullptr) {
        //Testing to see if a deep copy was indeed made.
        std::cout<<boatman<<std::endl;
        std::cout<< cloned_boatman<<std::endl;
        ++passed;
        std::cout << GREEN << "\tTest 2.3.1 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 2.3.1 Failed" << RESET << std::endl;
    }

    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }
    std::cout << "\nTest 3: Template Method Pattern" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    std::cout << "Test 3.1: Infantry Engage and Disengage:" << std::endl;
    passed = 0;
    total = 0;

    ++total;
    try {
        infantry_unit->engage();
        infantry_unit->disengage();
        ++passed;
        std::cout << GREEN << "\tTest 3.1.1 Passed" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "\tTest 3.1.1 Failed - Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3.2: ShieldBearer Engage and Disengage:" << std::endl;

    ++total;
    try {
        shieldbearer->engage();
        shieldbearer->disengage();
        ++passed;
        std::cout << GREEN << "\tTest 3.2.1 Passed" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "\tTest 3.2.1 Failed - Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3.3: Boatman Engage and Disengage:" << std::endl;

    ++total;
    try {
        boatman->engage();
        boatman->disengage();
        ++passed;
        std::cout << GREEN << "\tTest 3.3.1 Passed" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "\tTest 3.3.1 Failed - Exception: " << e.what() << RESET << std::endl;
    }

    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }

    // Clean up
    delete soldiers_factory;
    delete infantry_unit;
    delete cloned_infantry;
    delete shieldbearer;
    delete cloned_shieldbearer;
    delete boatman;
    delete cloned_boatman;

    return 0;
}
