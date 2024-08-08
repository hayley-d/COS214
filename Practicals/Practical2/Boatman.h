#ifndef BOATMAN_H
#define BOATMAN_H

#include "Soldiers.h"
#include <iostream>

class Boatman : public Soldiers {
public:
    Boatman();

    ~Boatman() override;

    Boatman(int amountOfSoldiersPerUnit, int damagePerSoldier, int defencePerSoldier, int healthPerSolider,
            const std::string &unitName);

    void vivificaMemento(ConcreteMemento &mem) override;

    ConcreteMemento *militusMemento() override;

    Soldiers *clonis() const override;

    Boatman(const Boatman &other);

    void prepare() const override {
        std::cout << "Boatman preparing for battle...." << std::endl;
    }

    void execute() const override {
        std::cout << "Boatman executing battle." << std::endl;
    }

    void retreat() const override {
        std::cout << "Boatman retreating from battle...." << std::endl;
    }

    void rest() const override {
        std::cout << "Boatman resting after battle." << std::endl;
    }
};


#endif //BOATMAN_H
