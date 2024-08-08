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

    Soldiers *clonis() const override {
        return new ShieldBearer(*this);
    }

    ShieldBearer(const ShieldBearer &other) : Soldiers(other) {
        healthPerSoldier = other.healthPerSoldier;
        damagePerSoldier = other.damagePerSoldier;
        defencePerSoldier = other.defencePerSoldier;
        amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
        unitName = other.unitName;
    }

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
