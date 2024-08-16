#include <iostream>

#include "Legion.h"

const std::string red = "\033[31m";
const std::string green = "\033[32m";
const std::string reset = "\033[0m";

/*std::string printCavalry() {
    return "        ,--,\n"
            "  _ ___/ /\\|\n"
            " ;( )__, )\n"
            " ; //   '--;\n"
            "  \\     |\n"
            "   ^    ^";
}*/


int main() {
    std::cout << "Legion Test" << std::endl;
    int passed = 0;
    int total = 0;

    ++total;
    Legion legion1{};
    if (legion1.getUnitName() == "Legion Unit") {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getDefence() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getStrength() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    const std::list<UnitComponent *> legion1_units = legion1.getUnits();
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
    Legion legion2{"Legion Unit 2"};
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
    legion1 = legion2;
    if(legion1.getUnitName() == "Legion Unit 2") {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }


    return 0;
}
