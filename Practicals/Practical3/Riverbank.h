#ifndef RIVERBANK_H
#define RIVERBANK_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class RiverbankInfantry : public Infantry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};

class RiverbankCavalry : public Cavalry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};

class RiverbankArtillery : public Artillery {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};



#endif //RIVERBANK_H
