#ifndef CONCRETEMEMENTO_H
#define CONCRETEMEMENTO_H

#include "Soldiers.h"
#include "Memento.h"

class Soldiers;

class ConcreteMemento : public Memento{
    friend class Soldiers;
private:
    int amountOfSoldiersPerUnit;
    int damagePerSoldier;
    int defencePerSoldier;
    int healthPerSoldier;
    std::string unitName;

    ConcreteMemento(int amountOfSoldiersPerUnit, int damagePerSoldier, int defencePerSoldier, int healthPerSoldier, const std::string& unitName);

public:
    ~ConcreteMemento() override;

    int getHealthPerSoldier() const override ;

    int getDamagePerSoldier() const override ;

    int getDefencePerSoldier() const override ;

    int getAmountOfSoldiersPerUnit() const override  ;

    std::string getUnitName() const override;
};



#endif //CONCRETEMEMENTO_H
