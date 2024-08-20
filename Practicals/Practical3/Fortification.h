#ifndef FORTIFICATION_H
#define FORTIFICATION_H


#include "BattleStrategy.h"

class Fortification : public BattleStrategy{
public:
    void engage(std::shared_ptr<UnitComponent> &unit) override;

    ~Fortification() override;
};



#endif //FORTIFICATION_H
