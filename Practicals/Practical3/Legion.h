#ifndef LEGION_H
#define LEGION_H

#include "CompositeUnit.h"
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <list>

#include "Cohort.h"
#include "Direction.h"

class Legion : public CompositeUnit{

    std::list<Cohort*> units;
    std::string unitName;
    int x;
    int y;

public:
    Legion() : unitName("Legion Unit"), x(0), y(0){}

    explicit Legion(std::string unitName): unitName(std::move(unitName)), x(0), y(0) {}

    Legion(std::string  unitName,const int x, const int y) :  unitName(std::move(unitName)), x(x), y(y){}

    Legion(const Legion& other);

    Legion& operator=(const Legion& other);

    bool operator<(const Legion& other) const;

    bool operator==(const Legion& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    bool add(UnitComponent *component) ;

    bool remove(UnitComponent *component) ;

    int getDamage() const override;

    int getDefence() const override;

    int getHealth() const override;

    int getX() const override{return x;}

    int getY() const override{return y;}

    const std::list<UnitComponent *>& getUnits() const override{return units;}

    ~Legion() override;

    std::string getUnitName(){return unitName;}

};



#endif //LEGION_H
