#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>

class Memento {
public:
    virtual int getHealthPerUnit() =0;
    virtual int getDamagePerUnit() =0;
    virtual int getDefencePerUnit() =0;
    virtual int getAmountOfSoldiersPerUnit() =0;
    virtual std::string getUnitName() =0;
    virtual ~Memento() = 0;
};



#endif //MEMENTO_H
