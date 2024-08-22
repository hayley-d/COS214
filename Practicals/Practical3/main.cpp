#include <iostream>

#include "Artillery.h"
#include "Legion.h"
#include "Infantry.h"
#include "UnitComponent.h"

const std::string red = "\033[31m";
const std::string green = "\033[32m";
const std::string reset = "\033[0m";


int main() {
    std::cout << "Legion Test" << std::endl;
    int passed = 0;
    int total = 0;

    ++total;
    Legion legion1{};
    if (legion1.getDefence() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getDamage() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getHealth() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getSize() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    const std::list<std::shared_ptr<UnitComponent>> legion1_units = legion1.getUnits();
    if (legion1_units.empty()) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    legion1.fight(Direction::East);
    legion1.fight(Direction::North);
    legion1.fight(Direction::South);
    legion1.fight(Direction::West);
    legion1.move(Direction::East);
    legion1.move(Direction::North);
    legion1.move(Direction::South);
    legion1.move(Direction::West);

    if (true) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    Legion legion2;
    if(legion1==legion2) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if(legion1<legion2 == false) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    std::shared_ptr<UnitComponent> infantry1 = std::make_shared<Infantry>();
    legion1.add(infantry1);
    if(legion1.getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if(legion1.getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if(legion2.getSize() == 0) {
        legion2 = legion1;
        if(legion2.getSize() == 1) {
         ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
        }
    }

    return 0;
}
