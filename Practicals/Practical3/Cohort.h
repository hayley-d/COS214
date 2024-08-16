#ifndef COHORT_H
#define COHORT_H

#include "CompositeUnit.h"
#include<string>

#include "Century.h"

class Cohort : public CompositeUnit {
    std::list<Century *> units;
    std::string unitName;
    int x;
    int y;

public:
    Cohort() : unitName("Cohort Unit"), x(0), y(0){}

    explicit Cohort(std::string unitName): unitName(std::move(unitName)), x(0), y(0) {}

    Cohort(std::string  unitName,const int x, const int y) :  unitName(std::move(unitName)), x(x), y(y){}

    Cohort(const Cohort& other);

    Cohort& operator=(const Cohort& other);

    bool operator<(const Cohort& other) const;

    bool operator==(const Cohort& other) const;

    void move(Direction direction) override;

    void fight(Direction direction) override;

    int getDamage() const override;

    int getDefence() const override;

    bool add(UnitComponent *component) override;

    bool remove(UnitComponent *component) override;

    const std::list<UnitComponent *> &getUnits() const override;

    ~Cohort() override;

    int getHealth() const override;

    int getX() const override{return x;}

    int getY() const override{return y;}
};


#endif //COHORT_H
