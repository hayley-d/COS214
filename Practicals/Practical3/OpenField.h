#ifndef OPENFIELD_H
#define OPENFIELD_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class OpenFieldInfantry : public Infantry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};

class OpenFieldCavalry : public Cavalry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};

class OpenFieldArtillery : public Artillery {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;
};



#endif //OPENFIELD_H
