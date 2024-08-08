#ifndef SHIELDBEARER_H
#define SHIELDBEARER_H

#include "Soldiers.h"
#include <iostream>

class ShieldBearer : public Soldiers {
public:
    ShieldBearer();

    ~ShieldBearer() override;

    ShieldBearer(int amountOfSoldiersPerUnit, int damagePerSoldier, int defencePerSoldier, int healthPerSolider,
                 const std::string &unitName);

    Soldiers *clonis() const override;

    ShieldBearer(const ShieldBearer &other);

    void prepare() const override {
        std::cout << "ShieldBearer preparing for battle...." << std::endl;
    }

    void execute() const override {
        std::cout << "ShieldBearer executing battle." << std::endl;
    }

    void retreat() const override {
        std::cout << "ShieldBearer retreating from battle...." << std::endl;
    }

    void rest() const override {
        std::cout << "ShieldBearer resting after battle." << std::endl;
    }
};


#endif //SHIELDBEARER_H
