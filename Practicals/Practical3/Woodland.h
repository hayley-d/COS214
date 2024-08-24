#ifndef WOODLANDS_H
#define WOODLANDS_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class WoodlandInfantry : public Infantry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~WoodlandInfantry() override {}

    UnitComponent *clone() override;
};

class WoodlandCavalry : public Cavalry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    UnitComponent *clone() override;

    ~WoodlandCavalry() override {}
};

class WoodlandArtillery : public Artillery {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    UnitComponent *clone() override;

    ~WoodlandArtillery() override {}
};

#endif //WOODLANDS_H
