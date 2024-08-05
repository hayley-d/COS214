#ifndef SOLDIERS_H
#define SOLDIERS_H

#include <string>

#include "ConcreteMemento.h"


class Soldiers {
protected:
    int amountOfSoldiersPerUnit;
    int damagePerSoldier;
    int defencePerSoldier;
    int healthPerSoldier;
    std::string unitName;

public:
    Soldiers();
    virtual ~Soldiers();
    Soldiers(int amountOfSoldiersPerUnit, int damagePerSoldier, int defencePerSoldier, int healthPerSoldier, const std::string& unitName);

    int getAmountOfSoldiersPerUnit() const {
        return amountOfSoldiersPerUnit;
    }

    int getDamagePerSoldier() const {
        return damagePerSoldier;
    }

    int getDefencePerSoldier() const {
        return defencePerSoldier;
    }

    int getHealthPerSoldier() const {
        return healthPerSoldier;
    }

    std::string getUnitName() const {
        return unitName;
    }

    virtual void setAmountOfSoldiersPerUnit(int amountOfSoldiersPerUnit) {}
    virtual void setDamagePerSoldier(int damagePerSoldier);
    virtual void setDefencePerSoldier(int defencePerSoldier);
    virtual void setHealthPerSoldier(int healthPerSoldier);
    virtual void setUnitName(const std::string& unitName);

    virtual void vivificaMemento(ConcreteMemento& mem);
    virtual ConcreteMemento* militusMemento();
};



#endif //SOLDIERS_H
