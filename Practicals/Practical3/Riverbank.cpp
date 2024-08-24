#include "Riverbank.h"

void RiverbankInfantry::move(Direction direction) {
    Infantry::move(direction);
}

void RiverbankInfantry::fight(Direction direction) {
    Infantry::fight(direction);
}

void RiverbankCavalry::move(Direction direction) {
    Cavalry::move(direction);
}

void RiverbankCavalry::fight(Direction direction) {
    Cavalry::fight(direction);
}

void RiverbankArtillery::move(Direction direction) {
    Artillery::move(direction);
}

void RiverbankArtillery::fight(Direction direction) {
    Artillery::fight(direction);
}
