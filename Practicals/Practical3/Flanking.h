#ifndef FLANKING_H
#define FLANKING_H

#include "BattleStrategy.h"


class Flanking : public BattleStrategy {

public:
    Flanking(const float successRate, const int minTroops, const int damagePotential, const int defenceBonus, const int executionTime,
             const Terrain bestEnviroment, const int riskLevel) : BattleStrategy(successRate,minTroops,damagePotential,defenceBonus,executionTime,
             bestEnviroment,riskLevel){
    }

    void engage(std::shared_ptr<UnitComponent>& unit) override;

    ~Flanking() override;


};


#endif //FLANKING_H
