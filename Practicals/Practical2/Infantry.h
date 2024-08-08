#ifndef INFANTRY_H
#define INFANTRY_H

#include "Soldiers.h"
#include <iostream>

class Infantry : public Soldiers {
public:
    Infantry();

    Infantry(int amountOfSoldiersPerUnit, int damagePerSoldier, int defencePerSoldier, int healthPerSolider,
             const std::string &unitName);

    ~Infantry() override;

    ConcreteMemento *militusMemento() override;

    Soldiers *clonis() const override;

    Infantry(const Infantry &other);

    void prepare() const override {
        std::cout << "Infantry preparing for battle...." << std::endl;
    }

    void execute() const override {
        std::cout << "Infantry executing battle." << std::endl;
    }

    void retreat() const override {
        std::cout << "Infantry retreating from battle...." << std::endl;
    }

    void rest() const override {
        std::cout << "Infantry resting after battle." << std::endl;
    }
};


#endif //INFANTRY_H
