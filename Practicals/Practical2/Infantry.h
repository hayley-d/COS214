#ifndef INFANTRY_H
#define INFANTRY_H

#include "Soldiers.h"
#include <iostream>

class Infantry : public Soldiers{
public:
    Infantry();
    ~Infantry() override;

    ConcreteMemento * militusMemento() override;

    Soldiers* clonis() const override{
        return new Infantry(*this);
    }

    Infantry(const Infantry& other) : Soldiers(other){
        healthPerSoldier = other.healthPerSoldier;
        damagePerSoldier = other.damagePerSoldier;
        defencePerSoldier = other.defencePerSoldier;
        amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
        unitName = other.unitName;
    }

    void prepare() const override{
        std::cout<<"Infantry preparing for battle...."<<std::endl;
    }
    void execute() const override{
        std::cout<<"Infantry executing battle."<<std::endl;
    }
    void retreat() const override{
        std::cout<<"Infantry retreating from battle...."<<std::endl;
    }
    void rest() const override{
        std::cout<<"Infantry resting after battle."<<std::endl;
    }
};



#endif //INFANTRY_H
