#ifndef BOATMAN_H
#define BOATMAN_H

#include "Soldiers.h"
#include <iostream>

class Boatman : public Soldiers{
public:
    Boatman();
    ~Boatman() override;

    void vivificaMemento(ConcreteMemento &mem) override;

    ConcreteMemento * militusMemento() override;

    Soldiers* clonis() const override{
        return new Boatman(*this);
    }

    Boatman(const Boatman &other) : Soldiers(other){
        healthPerSoldier = other.healthPerSoldier;
        damagePerSoldier = other.damagePerSoldier;
        defencePerSoldier = other.defencePerSoldier;
        amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
        unitName = other.unitName;
    }

    void prepare() const override{
        std::cout<<"Boatman preparing for battle...."<<std::endl;
    }
    void execute() const override{
        std::cout<<"Boatman executing battle."<<std::endl;
    }
    void retreat() const override{
        std::cout<<"Boatman retreating from battle...."<<std::endl;
    }
    void rest() const override{
        std::cout<<"Boatman resting after battle."<<std::endl;
    }
};



#endif //BOATMAN_H
