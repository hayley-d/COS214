#ifndef FORTIFICATION_H
#define FORTIFICATION_H


#include "BattleStrategy.h"

class Fortification : public BattleStrategy{
public:
    void engage(UnitComponent &unit) override;

    ~Fortification() override;
};



#endif //FORTIFICATION_H
