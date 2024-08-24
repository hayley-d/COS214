#ifndef FORTIFICATION_H
#define FORTIFICATION_H


#include "BattleStrategy.h"

class Fortification : public BattleStrategy{
public:
    Fortification(float successRate, int minTroops, int damagePotential, int defenceBonus, int executionTime,
        Terrain bestEnviroment, int riskLevel)
        : BattleStrategy(
            successRate, minTroops, damagePotential, defenceBonus, executionTime, bestEnviroment, riskLevel) {
    }

    void engage(UnitComponent&unit,UnitComponent &enemy) override;

    ~Fortification() override;

    BattleStrategy * clone() const override;
};



#endif //FORTIFICATION_H
