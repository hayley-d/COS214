
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

int main2() {
    std::cout << "Test 1: Factory Pattern" << std::endl;
    std::cout << "-----------------------" << std::endl;

    std::cout << "Test 1.1: Infantry Factory Test:" << std::endl;
    int passed = 0;
    int total = 0;

    //test constructor
    auto *soldiers_factory = new InfantryFactory();

    ++total;
    if (soldiers_factory->calculateTotalHealthPerUnit() == (50 * 8)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Health Failed" << RESET << std::endl;
    }

    ++total;
    if (soldiers_factory->calculateTotalDamagePerUnit() == (40 * 8)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Damage Failed" << RESET << std::endl;
    }

    ++total;
    if (soldiers_factory->calculateTotalDefencePerUnit() == (20 * 8)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Defence Failed" << RESET << std::endl;
    }

    ++total;
    Infantry *infantry_unit = dynamic_cast<Infantry *>(soldiers_factory->createUnit());
    if (infantry_unit != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest Create Unit Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Create Unit Failed" << RESET << std::endl;
    }

    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }

    std::cout << "Test 1.2: ShieldBearer Factory Test:" << std::endl;
    passed = 0;
    total = 0;

    //test constructor
    auto *shield_factory = new ShieldBearerFactory();

    ++total;
    if (shield_factory->calculateTotalHealthPerUnit() == (3 * 40)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Health Failed" << RESET << std::endl;
    }

    ++total;
    if (shield_factory->calculateTotalDamagePerUnit() == (3 * 20)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Damage Failed" << RESET << std::endl;
    }

    ++total;
    if (shield_factory->calculateTotalDefencePerUnit() == (90 * 3)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Defence Failed" << RESET << std::endl;
    }

    ++total;
    ShieldBearer *shield_unit = dynamic_cast<ShieldBearer *>(shield_factory->createUnit());
    if (shield_unit != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest Create Unit Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Create Unit Failed" << RESET << std::endl;
    }

    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }

    std::cout << "Test 1.3: Boatman Factory Test:" << std::endl;
    passed = 0;
    total = 0;

    //test constructor
    auto *boat_factory = new BoatmanFactory();

    ++total;
    if (boat_factory->calculateTotalHealthPerUnit() == (20 * 20)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Health Failed" << RESET << std::endl;
    }

    ++total;
    if (boat_factory->calculateTotalDamagePerUnit() == (50 * 20)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Damage Failed" << RESET << std::endl;
    }

    ++total;
    if (boat_factory->calculateTotalDefencePerUnit() == (0)) {
        ++passed;
        std::cout << GREEN << "\tTest Total Defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Total Defence Failed" << RESET << std::endl;
    }

    ++total;
    Boatman *boat_unit = dynamic_cast<Boatman *>(boat_factory->createUnit());
    if (boat_unit != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest Create Unit Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest Create Unit Failed" << RESET << std::endl;
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
    Infantry *cloned_infantry = dynamic_cast<Infantry *>(infantry_unit->clonis());
    if (cloned_infantry != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest 2.1.1 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 2.1.1 Failed" << RESET << std::endl;
    }

    std::cout << "Test 2.2: Cloning ShieldBearer:" << std::endl;

    // Test ShieldBearer cloning
    /*auto *shieldbearer = new ShieldBearer();*/
    ++total;
    ShieldBearer *cloned_shieldbearer = dynamic_cast<ShieldBearer *>(shield_unit->clonis());
    if (cloned_shieldbearer != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest 2.2.1 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 2.2.1 Failed" << RESET << std::endl;
    }

    std::cout << "Test 2.3: Cloning Boatman:" << std::endl;

    // Test Boatman cloning
    /*auto *boatman = new Boatman();*/
    ++total;
    Boatman *cloned_boatman = dynamic_cast<Boatman *>(boat_unit->clonis());
    if (cloned_boatman != nullptr && boat_unit != cloned_boatman) {
        //Testing to see if a deep copy was indeed made.
        /*std::cout << boatman << std::endl;
        std::cout << cloned_boatman << std::endl;*/
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
    } catch (const std::exception &e) {
        std::cout << RED << "\tTest 3.1.1 Failed - Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3.2: ShieldBearer Engage and Disengage:" << std::endl;

    ++total;
    try {
        shield_unit->engage();
        shield_unit->disengage();
        ++passed;
        std::cout << GREEN << "\tTest 3.2.1 Passed" << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << "\tTest 3.2.1 Failed - Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3.3: Boatman Engage and Disengage:" << std::endl;

    ++total;
    try {
        boat_unit->engage();
        boat_unit->disengage();
        ++passed;
        std::cout << GREEN << "\tTest 3.3.1 Passed" << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << "\tTest 3.3.1 Failed - Exception: " << e.what() << RESET << std::endl;
    }

    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }

    ////////////////////////////////////
    std::cout << "Soldier Test:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    passed = 0;
    total = 0;

    auto *infantry_state = new Infantry();
    auto *boatman_state = new Boatman();
    auto *shield_state = new ShieldBearer();

    ++total;
    infantry_state->setUnitName("Tom's Infantry");
    if (infantry_state->getUnitName() == "Tom's Infantry") {
        ++passed;
        std::cout << GREEN << "\tTest get/set unit name Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set unit name Failed" << RESET << std::endl;
    }

    ++total;
    infantry_state->setDamagePerSoldier(-1);
    if (infantry_state->getDamagePerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative damage Failed" << RESET << std::endl;
    }

    ++total;
    infantry_state->setDefencePerSoldier(-1);
    if (infantry_state->getDefencePerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative defence Failed" << RESET << std::endl;
    }

    ++total;
    infantry_state->setHealthPerSoldier(-1);
    if (infantry_state->getHealthPerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative health Failed" << RESET << std::endl;
    }

    ++total;
    infantry_state->setAmountOfSoldiersPerUnit(-100);
    if (infantry_state->getAmountOfSoldiersPerUnit() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative amount of soldiers Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative amount of soldiers Failed" << RESET << std::endl;
    }

    ++total;
    infantry_state->setDamagePerSoldier(100);
    if (infantry_state->getDamagePerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set damage Failed" << RESET << std::endl;
    }

    ++total;
    infantry_state->setDefencePerSoldier(100);
    if (infantry_state->getDefencePerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set defence Failed" << RESET << std::endl;
    }

    ++total;
    infantry_state->setHealthPerSoldier(100);
    if (infantry_state->getHealthPerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set health Failed" << RESET << std::endl;
    }

    ++total;
    infantry_state->setAmountOfSoldiersPerUnit(100);
    if (infantry_state->getAmountOfSoldiersPerUnit() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set amount of soldiers Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set amount of soldiers Failed" << RESET << std::endl;
    }


    ++total;
    boatman_state->setUnitName("Tom's Navy");
    if (boatman_state->getUnitName() == "Tom's Navy") {
        ++passed;
        std::cout << GREEN << "\tTest get/set unit name Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set unit name Failed" << RESET << std::endl;
    }

    ++total;
    boatman_state->setDamagePerSoldier(-1);
    if (boatman_state->getDamagePerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative damage Failed" << RESET << std::endl;
    }

    ++total;
    boatman_state->setDefencePerSoldier(-1);
    if (boatman_state->getDefencePerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative defence Failed" << RESET << std::endl;
    }

    ++total;
    boatman_state->setHealthPerSoldier(-1);
    if (boatman_state->getHealthPerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative health Failed" << RESET << std::endl;
    }

    ++total;
    boatman_state->setAmountOfSoldiersPerUnit(-100);
    if (boatman_state->getAmountOfSoldiersPerUnit() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative amount of soldiers Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative amount of soldiers Failed" << RESET << std::endl;
    }

    ++total;
    boatman_state->setDamagePerSoldier(100);
    if (boatman_state->getDamagePerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set damage Failed" << RESET << std::endl;
    }

    ++total;
    boatman_state->setDefencePerSoldier(100);
    if (boatman_state->getDefencePerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set defence Failed" << RESET << std::endl;
    }

    ++total;
    boatman_state->setHealthPerSoldier(100);
    if (boatman_state->getHealthPerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set health Failed" << RESET << std::endl;
    }

    ++total;
    boatman_state->setAmountOfSoldiersPerUnit(100);
    if (boatman_state->getAmountOfSoldiersPerUnit() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set amount of soldiers Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set amount of soldiers Failed" << RESET << std::endl;
    }


    ++total;
    shield_state->setUnitName("Tom's Shields");
    if (shield_state->getUnitName() == "Tom's Shields") {
        ++passed;
        std::cout << GREEN << "\tTest get/set unit name Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set unit name Failed" << RESET << std::endl;
    }

    ++total;

    shield_state->setDamagePerSoldier(-1);
    if (shield_state->getDamagePerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative damage Failed" << RESET << std::endl;
    }

    ++total;
    shield_state->setDefencePerSoldier(-1);
    if (shield_state->getDefencePerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative defence Failed" << RESET << std::endl;
    }

    ++total;
    shield_state->setHealthPerSoldier(-1);
    if (shield_state->getHealthPerSoldier() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative health Failed" << RESET << std::endl;
    }

    ++total;
    shield_state->setAmountOfSoldiersPerUnit(-100);
    if (shield_state->getAmountOfSoldiersPerUnit() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest get/set negative amount of soldiers Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set negative amount of soldiers Failed" << RESET << std::endl;
    }

    ++total;
    shield_state->setDamagePerSoldier(100);
    if (shield_state->getDamagePerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set damage Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set damage Failed" << RESET << std::endl;
    }

    ++total;
    shield_state->setDefencePerSoldier(100);
    if (shield_state->getDefencePerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set defence Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set defence Failed" << RESET << std::endl;
    }

    ++total;
    shield_state->setHealthPerSoldier(100);
    if (shield_state->getHealthPerSoldier() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set health Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set health Failed" << RESET << std::endl;
    }

    ++total;
    shield_state->setAmountOfSoldiersPerUnit(100);
    if (shield_state->getAmountOfSoldiersPerUnit() == 100) {
        ++passed;
        std::cout << GREEN << "\tTest get/set amount of soldiers Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest get/set amount of soldiers Failed" << RESET << std::endl;
    }

    std::cout << "Ending Soldier Test" << std::endl;
    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }

    ////////////////////////////////////
    std::cout << "Militus Memento Test:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    passed = 0;
    total = 0;

    ConcreteMemento *infantry_memento = infantry_state->militusMemento();
    ConcreteMemento *boat_memento = boatman_state->militusMemento();
    ConcreteMemento *shield_memento = shield_state->militusMemento();

    ++total;
    if (infantry_memento != nullptr && boat_memento != nullptr && shield_memento != nullptr) {
        ++passed;
        std::cout << GREEN << "\tTest 1 militusMemento Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 1 militusMemento Failed" << RESET << std::endl;
    }

    ++total;
    if (infantry_memento->getDamagePerSoldier() == 100 && infantry_memento->getDefencePerSoldier() == 100 &&
        infantry_memento->getAmountOfSoldiersPerUnit() == 100 && infantry_memento->getHealthPerSoldier() == 100 &&
        infantry_memento->getUnitName() == "Tom's Infantry") {
        ++passed;
        std::cout << GREEN << "\tTest 2 Infanty Memento attributes Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 2 Infanty Memento attributes Failed" << RESET << std::endl;
    }

    ++total;
    if (boat_memento->getDamagePerSoldier() == 100 && boat_memento->getDefencePerSoldier() == 100 && boat_memento->
        getAmountOfSoldiersPerUnit() == 100 && boat_memento->getHealthPerSoldier() == 100 && boat_memento->getUnitName()
        == "Tom's Navy") {
        ++passed;
        std::cout << GREEN << "\tTest 3 Boatman Memento attributes Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 3 Boatman Memento attributes Failed" << RESET << std::endl;
    }

    ++total;
    if (shield_memento->getDamagePerSoldier() == 100 && shield_memento->getDefencePerSoldier() == 100 && shield_memento
        ->getAmountOfSoldiersPerUnit() == 100 && shield_memento->getHealthPerSoldier() == 100 && shield_memento->
        getUnitName() == "Tom's Shields") {
        ++passed;
        std::cout << GREEN << "\tTest 4 ShiledBearer Memento attributes Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest 4 ShiledBearer Memento attributes Failed" << RESET << std::endl;
    }

    std::cout << "Ending Militus Memento Test" << std::endl;
    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }


    std::cout << "CareTaker/Memento Test:" << std::endl;
    std::cout << "-----------------------" << std::endl;
    passed = 0;
    total = 0;

    CareTaker care_taker;

    std::cout << "Testing CareTaker Stack......" << std::endl;

    ++total;
    if (care_taker.getSize() == 0) {
        ++passed;
        std::cout << GREEN << "\tTest stack initilization Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest stack initilization Failed" << RESET << std::endl;
    }

    care_taker.saveState(*infantry_state);

    ++total;
    if (care_taker.getSize() == 1) {
        ++passed;
        std::cout << GREEN << "\tTest save state #1 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest save state #1 Failed" << RESET << std::endl;
    }

    care_taker.saveState(*boatman_state);

    ++total;
    if (care_taker.getSize() == 2) {
        ++passed;
        std::cout << GREEN << "\tTest save state #2 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest save state #2 Failed" << RESET << std::endl;
    }

    care_taker.saveState(*shield_state);

    ++total;
    if (care_taker.getSize() == 3) {
        ++passed;
        std::cout << GREEN << "\tTest save state #3 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tTest save state #3 Failed" << RESET << std::endl;
    }

    std::cout << "Ending CareTaker Stack Test" << std::endl;
    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }

    std::cout << "Testing Memento Restore State...." << std::endl;
    passed = 0;
    total = 0;

    //change the state so can check if restores old state
    infantry_state->setDamagePerSoldier(10);
    infantry_state->setDefencePerSoldier(10);
    infantry_state->setHealthPerSoldier(10);
    infantry_state->setAmountOfSoldiersPerUnit(10);
    infantry_state->setUnitName("Renamed Infantry");

    boatman_state->setDamagePerSoldier(10);
    boatman_state->setDefencePerSoldier(10);
    boatman_state->setHealthPerSoldier(10);
    boatman_state->setAmountOfSoldiersPerUnit(10);
    boatman_state->setUnitName("Renamed Boatman");

    shield_state->setDamagePerSoldier(10);
    shield_state->setDefencePerSoldier(10);
    shield_state->setHealthPerSoldier(10);
    shield_state->setAmountOfSoldiersPerUnit(10);
    shield_state->setUnitName("Renamed ShieldBearer");

    ++total;
    if (infantry_state->getDamagePerSoldier() == 10 && infantry_state->getDefencePerSoldier() == 10 && infantry_state->
        getAmountOfSoldiersPerUnit() == 10) {
        ++passed;
        std::cout << GREEN << "\tChange State Infantry Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tChange State Infantry Failed" << RESET << std::endl;
    }

    infantry_state->vivificaMemento(*care_taker.undo());
    ++total;
    if (infantry_state->getDamagePerSoldier() == 100 && infantry_state->getDefencePerSoldier() == 100 && infantry_state
        ->getAmountOfSoldiersPerUnit() == 100) {
        ++passed;
        std::cout << GREEN << "\tRestore state Infantry Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tRestore state Infantry Failed" << RESET << std::endl;
    }

    ++total;
    if (boatman_state->getDamagePerSoldier() == 10 && boatman_state->getDefencePerSoldier() == 10 && boatman_state->
        getAmountOfSoldiersPerUnit() == 10) {
        ++passed;
        std::cout << GREEN << "\tChange State Boatman Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tChange State Boatman Failed" << RESET << std::endl;
    }

    boatman_state->vivificaMemento(*care_taker.undo());
    ++total;
    if (boatman_state->getDamagePerSoldier() == 100 && boatman_state->getDefencePerSoldier() == 100 && boatman_state->
        getAmountOfSoldiersPerUnit() == 100) {
        ++passed;
        std::cout << GREEN << "\tRestore state Boatman Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tRestore state Boatman Failed" << RESET << std::endl;
    }

    ++total;
    if (shield_state->getDamagePerSoldier() == 10 && shield_state->getDefencePerSoldier() == 10 && shield_state->
        getAmountOfSoldiersPerUnit() == 10) {
        ++passed;
        std::cout << GREEN << "\tChange State ShieldBearer Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tChange State ShieldBearer Failed" << RESET << std::endl;
    }

    shield_state->vivificaMemento(*care_taker.undo());
    ++total;
    if (shield_state->getDamagePerSoldier() == 100 && shield_state->getDefencePerSoldier() == 100 && shield_state->
        getAmountOfSoldiersPerUnit() == 100) {
        ++passed;
        std::cout << GREEN << "\tRestore state ShieldBearer Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tRestore state ShieldBearer Failed" << RESET << std::endl;
    }

    std::cout << "Ending CareTaker Restore Test" << std::endl;
    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }

    std::cout << "Testing Soldier hierachy constructors...." << std::endl;
    passed = 0;
    total = 0;

    Infantry infantry_unit_2(1, 1, 1, 1, "unit2");

    ++total;
    if (infantry_unit_2.getUnitName() == "unit2" && infantry_unit_2.getDamagePerSoldier() == 1 && infantry_unit_2.
        getDefencePerSoldier() == 1 && infantry_unit_2.getHealthPerSoldier() == 1 && infantry_unit_2.
        getAmountOfSoldiersPerUnit() == 1) {
        ++passed;
        std::cout << GREEN << "\tInfantry Constructor Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tInfantry Constructor Failed" << RESET << std::endl;
    }

    Boatman boatman_unit_2(1, 1, 1, 1, "unit2");

    ++total;
    if (boatman_unit_2.getUnitName() == "unit2" && boatman_unit_2.getDamagePerSoldier() == 1 && boatman_unit_2.
        getDefencePerSoldier() == 1 && boatman_unit_2.getHealthPerSoldier() == 1 && boatman_unit_2.
        getAmountOfSoldiersPerUnit() == 1) {
        ++passed;
        std::cout << GREEN << "\tBoatman Constructor Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tBoatman Constructor Failed" << RESET << std::endl;
    }

    ShieldBearer shield_unit_2(1, 1, 1, 1, "unit2");

    ++total;
    if (shield_unit_2.getUnitName() == "unit2" && shield_unit_2.getDamagePerSoldier() == 1 && shield_unit_2.
        getDefencePerSoldier() == 1 && shield_unit_2.getHealthPerSoldier() == 1 && shield_unit_2.
        getAmountOfSoldiersPerUnit() == 1) {
        ++passed;
        std::cout << GREEN << "\tShieldBearer Constructor Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "\tShieldBearer Constructor Failed" << RESET << std::endl;
    }


    std::cout << "Ending Soldier Hierachy Constructor Test" << std::endl;
    if (total == passed) {
        std::cout << GREEN << "Passed " << passed << "/" << total << "\n" << RESET << std::endl;
    } else {
        std::cout << RED << "Failed " << passed << "/" << total << "\n" << RESET << std::endl;
    }


    // Clean up
    /*delete soldiers_factory;
    delete shield_factory;
    delete boat_factory;*/

    delete infantry_unit;
    delete shield_unit;
    delete boat_unit;

    delete cloned_infantry;
    delete cloned_shieldbearer;
    delete cloned_boatman;

    delete infantry_state;
    delete boatman_state;
    delete shield_state;
    delete infantry_memento;
    delete boat_memento;
    delete shield_memento;

    return 0;
}
