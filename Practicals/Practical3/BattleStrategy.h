#ifndef BATTLESTRATEGY_H
#define BATTLESTRATEGY_H
#include "UnitComponent.h"
#include <time.h>

enum class Terrain {
    Woodlands,
    Riverbank,
    OpenField
};

class BattleStrategy {
    float successRate; // success rate
    int minimumTroops; // minimum number of troops to succeed- if less then auto fail
    int damagePotential; // damage it can inflict if successful
    int defenceBonus; // add defence bonous to UnitComponent
    int executionTime; //time needed to execute the strategy (in rounds)
    Terrain bestEnviroment; // enviroment with the most success
    int riskLevel; //risk level out of 10

public:
    BattleStrategy(const float successRate, const int minTroops, const int damagePotential, const int defenceBonus, const int executionTime,
             const Terrain bestEnviroment, const int riskLevel) : successRate(successRate), minimumTroops(minTroops),
                                                      damagePotential(damagePotential), defenceBonus(defenceBonus),
                                                      executionTime(executionTime), bestEnviroment(bestEnviroment),
                                                      riskLevel(riskLevel) {}


    virtual void engage(UnitComponent& unit,UnitComponent &enemy) =0;

    virtual BattleStrategy* clone() const = 0;

    virtual ~BattleStrategy() = default;

    float getSuccessRate() const {
        return successRate;
    }

    int getMinimumTroops() const {
        return minimumTroops;
    }

    int getDamagePotential() const {
        return damagePotential;
    }

    int getDefenceBonus() const {
        return defenceBonus;
    }

    int getExecutionTime() const {
        return executionTime;
    }

    Terrain getBestEnviroment() const {
        return bestEnviroment;
    }

    int getRiskLevel() const {
        return riskLevel;
    }

    void setSuccessRate(const float successRate){
        this->successRate = successRate;
    }

    void setMinimumTroops(const int minimumTroops){
        this->minimumTroops = minimumTroops;
    }

    void setDamagePotential(const int damagePotential){
        this->damagePotential = damagePotential;
    }

    void setDefenceBonus(const int defenceBonus){
        this->defenceBonus = defenceBonus;
    }

    void setExecutionTime(const int executionTime){
        this->executionTime = executionTime;
    }

    void setBestEnviroment(const Terrain bestEnviroment){
        this->bestEnviroment = bestEnviroment;
    }

    void setRiskLevel(const int riskLevel){
        this->riskLevel = riskLevel;
    }
};



#endif //BATTLESTRATEGY_H
