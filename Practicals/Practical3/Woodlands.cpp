#include "Woodlands.h"
void WoodlandsInfantry::move(Direction direction) {
    Infantry::move(direction);
}

void WoodlandsInfantry::fight(Direction direction) {
    Infantry::fight(direction);
}

void WoodlandsCavalry::move(Direction direction) {
    Cavalry::move(direction);
}

void WoodlandsCavalry::fight(Direction direction) {
    Cavalry::fight(direction);
}

void WoodlandsArtillery::move(Direction direction) {
    Artillery::move(direction);
}

void WoodlandsArtillery::fight(Direction direction) {
    Artillery::fight(direction);
}
