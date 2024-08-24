#include "Woodland.h"

void WoodlandInfantry::fight(Direction direction) {
    Infantry::fight(direction);
    std::cout << "Infantry attacks from the woodlands " << direction << std::endl;
}

void WoodlandCavalry::fight(Direction direction) {
    Cavalry::fight(direction);
    std::cout << "Cavalry attacks from the woodlands " << direction << std::endl;
}

void WoodlandArtillery::fight(Direction direction) {
    Artillery::fight(direction);
    std::cout << "Artillery attacks from the woodlands " << direction << std::endl;
}

void WoodlandInfantry::move(Direction direction) {
    Infantry::move(direction);
    std::cout << "Infantry moves through the woodlands " << direction << std::endl;
}

void WoodlandArtillery::move(Direction direction) {
    Artillery::move(direction);
    std::cout << "Artillery moves through the woodlands " << direction << std::endl;
}

void WoodlandCavalry::move(Direction direction) {
    Cavalry::move(direction);
    std::cout << "Cavalry moves through the woodlands " << direction << std::endl;
}

UnitComponent *WoodlandInfantry::clone() {
    return new WoodlandInfantry(*this);
}

UnitComponent *WoodlandCavalry::clone() {
    return new WoodlandCavalry(*this);
}

UnitComponent *WoodlandArtillery::clone() {
    return new WoodlandArtillery(*this);
}

