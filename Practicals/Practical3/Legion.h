#ifndef LEGION_H
#define LEGION_H

#include "UnitComponent.h"

#include <string>
#include <iostream>
#include <list>
#include <memory>


#include "Direction.h"

class Legion : public UnitComponent{

    std::list<std::shared_ptr<UnitComponent>> units;

public:
    Legion() : UnitComponent(0,0,0,0,0){}

    Legion(const Legion& other);

    Legion& operator=(const Legion& other);

    bool operator<(const Legion& other) const;

    bool operator==(const Legion& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    bool add(std::shared_ptr<UnitComponent>&component) ;

    bool remove(std::shared_ptr<UnitComponent>&component) ;

    int getDamage() const override;

    int getDefence() const override;

    int getHealth() const override;

    int getX() const override{return x;}

    int getY() const override{return y;}

    const std::list<std::shared_ptr<UnitComponent>>& getUnits() const {return units;}

    ~Legion() override;

    std::shared_ptr<UnitComponent> clone() override;
};



#endif //LEGION_H
