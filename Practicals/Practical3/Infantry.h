#ifndef INFANTRY_H
#define INFANTRY_H

#include <utility>

#include "UnitComponent.h"

class Infantry : public UnitComponent{

    int defence;
    int attack;

public:
    Infantry() : defence(10), attack(10){}

    Infantry(const int defence, const int attack) : defence(defence), attack(attack){}

    Infantry(const Infantry &other);

    Infantry & operator=(const Infantry &other);

    bool operator<(const Infantry& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~Infantry() override;
};



#endif //INFANTRY_H
