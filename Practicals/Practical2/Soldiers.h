#ifndef SOLDIERS_H
#define SOLDIERS_H

#include <string>

#include "ConcreteMemento.h"


class Soldiers {
    int amountOfSoldiersPerUnit;
    int damagePerUnit;
    int defencePerUnit;
    int healthPerUnit;
    std::string unitName;

public:
    Soldiers();
    virtual ~Soldiers();
    Soldiers(int amountOfSoldiersPerUnit, int damagePerUnit, int defencePerUnit, int healthPerUnit, const std::string& unitName);

    int getAmountOfSoldiersPerUnit() const {
        return amountOfSoldiersPerUnit;
    }

    int getDamagePerUnit() const {
        return damagePerUnit;
    }

    int getDefencePerUnit() const {
        return defencePerUnit;
    }

    int getHealthPerUnit() const {
        return healthPerUnit;
    }

    std::string getUnitName() const {
        return unitName;
    }

    virtual void setAmountOfSoldiersPerUnit(int amountOfSoldiersPerUnit) {}
    virtual void setDamagePerUnit(int damagePerUnit);
    virtual void setDefencePerUnit(int defencePerUnit);
    virtual void setHealthPerUnit(int healthPerUnit);
    virtual void setUnitName(const std::string& unitName);

    virtual void vivificaMemento(ConcreteMemento& mem);
    virtual ConcreteMemento* militusMemento();
};



#endif //SOLDIERS_H
