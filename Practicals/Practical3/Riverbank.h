#ifndef RIVERBANK_H
#define RIVERBANK_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class RiverbankInfantry : public Infantry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~RiverbankInfantry() override {}

    UnitComponent * clone() override;
};

class RiverbankCavalry : public Cavalry{
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~RiverbankCavalry() override {}

    UnitComponent * clone() override;

};

class RiverbankArtillery : public Artillery {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~RiverbankArtillery() override {}

    UnitComponent * clone() override;

};



#endif //RIVERBANK_H
