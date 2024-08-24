#ifndef LEGION_H
#define LEGION_H

#include "UnitComponent.h"

#include <string>
#include <iostream>
#include <list>
#include <memory>


#include "Direction.h"

class Legion : public UnitComponent{

    std::list<UnitComponent*> units;

public:
    Legion() : UnitComponent(0,0,0,0,0,0){}

    Legion(const Legion& other);

    Legion& operator=(const Legion& other);

    bool operator<(const Legion& other) const;

    //bool operator==(const Legion& other) const;

    bool operator==(UnitComponent& other) override;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    bool add(UnitComponent&component) ;

    bool remove(UnitComponent&component) ;

    int getDamage() const override;

    int getDefence() const override;

    int getHealth() const override;

    int getSize() const override;

    int getX() const override{return x;}

    int getY() const override{return y;}

    const std::list<UnitComponent*>& getUnits() const {return units;}

    ~Legion() override;

    UnitComponent* clone() override;

    void applyDamage(int damage) override;

    void die() override;
};



#endif //LEGION_H
