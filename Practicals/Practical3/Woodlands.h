#ifndef WOODLANDS_H
#define WOODLANDS_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class WoodlandsInfantry : public Infantry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};

class WoodlandsCavalry : public Cavalry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};

class WoodlandsArtillery : public Artillery {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};

#endif //WOODLANDS_H
