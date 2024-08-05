#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>

class Memento {
public:
    virtual int getHealthPerSoldier() const =0;
    virtual int getDamagePerSoldier() const =0;
    virtual int getDefencePerSoldier() const =0;
    virtual int getAmountOfSoldiersPerUnit() const =0;
    virtual std::string getUnitName() const =0;
    virtual ~Memento() = 0;
};



#endif //MEMENTO_H
