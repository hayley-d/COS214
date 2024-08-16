#ifndef CENTURY_H
#define CENTURY_H

#include "CompositeUnit.h"
#include <string>

class Century : public CompositeUnit {
    std::list<UnitComponent *> units;
    std::string unitName;
    int x;
    int y;

public:
    Century() : unitName("Century Unit"), x(0), y(0){}

    explicit Century(std::string unitName): unitName(std::move(unitName)), x(0), y(0) {}

    Century(std::string  unitName,const int x, const int y) :  unitName(std::move(unitName)), x(x), y(y){}

    Century(const Century& other);

    Century& operator=(const Century& other);

    bool operator<(const Century& other) const;

    bool operator==(const Century& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    int getDamage() const override;

    int getDefence() const override;

    int getHealth() const override;

    int getX() const override;

    int getY() const override;

    bool add(UnitComponent *component) override;

    bool remove(UnitComponent *component) override;

    const std::list<UnitComponent *> &getUnits() const override;

    ~Century() override;
};


#endif //CENTURY_H
