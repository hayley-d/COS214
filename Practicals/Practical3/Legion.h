#ifndef LEGION_H
#define LEGION_H

#include "CompositeUnit.h"
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <list>

#include "Direction.h"

class Legion : public CompositeUnit{
protected:
    std::list<UnitComponent*> units;
    std::string unitName;

    bool isInUnit(const UnitComponent *component);

public:
    Legion() : unitName("Legion Unit"){}

    Legion(std::string   unitName): unitName(std::move(unitName)) {}

    Legion(std::string  unitName, std::list<UnitComponent*> units) :  units(std::move(units)), unitName(std::move(unitName)){}

    Legion(const Legion& other);

    Legion& operator=(const Legion& other);

    bool operator<(const Legion& other) const;

    bool operator==(const Legion& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    bool add(UnitComponent *component) ;

    bool remove(UnitComponent *component) ;

    int getStrength() const override;

    int getDefence() const override;

    const std::list<UnitComponent *>& getUnits() const override;

    ~Legion() override;

    std::string getUnitName(){return unitName;}

};



#endif //LEGION_H
