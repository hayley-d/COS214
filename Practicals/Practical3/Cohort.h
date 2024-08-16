#ifndef COHORT_H
#define COHORT_H

#include "CompositeUnit.h"

class Cohort : public CompositeUnit{

public:
    Cohort();

    Cohort(const Cohort& other);

    void move(Direction direction) override;

    void fight(Direction direction) override;

    int getStrength() const override;

    int getDefence() const override;

    bool add(UnitComponent *component) override;

    bool remove(UnitComponent *component) override;

    const std::list<UnitComponent *>& getUnits() const override;

    ~Cohort() override;
};



#endif //COHORT_H
