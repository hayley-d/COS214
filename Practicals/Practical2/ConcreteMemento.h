#ifndef CONCRETEMEMENTO_H
#define CONCRETEMEMENTO_H

#include "Soldiers.h"
#include "Memento.h"

class Soldiers;

class ConcreteMemento : public Memento{
    friend class Soldiers;
private:
    int amountOfSoldiersPerUnit;
    int damagePerUnit;
    int defencePerUnit;
    int healthPerUnit;
    std::string unitName;

    ConcreteMemento(int amountOfSoldiersPerUnit, int damagePerUnit, int defencePerUnit, int healthPerUnit, const std::string& unitName);

public:
    ~ConcreteMemento() override;

    int getHealthPerUnit() override;

    int getDamagePerUnit() override;

    int getDefencePerUnit() override;

    int getAmountOfSoldiersPerUnit() override;

    std::string getUnitName() override;
};



#endif //CONCRETEMEMENTO_H
