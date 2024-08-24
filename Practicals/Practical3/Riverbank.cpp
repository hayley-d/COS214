#include "Riverbank.h"

void RiverbankInfantry::move(Direction direction) {
     Infantry::move(direction);
    std::cout << "Infantry moves through the riverbank "<< direction << std::endl;
}

void RiverbankCavalry::move(Direction direction) {
    Cavalry::move(direction);
    std::cout << "Cavalry moves through the riverbank "<< direction << std::endl;
}

void RiverbankArtillery::move(Direction direction) {
Artillery::move(direction);
    std::cout << "Artillery moves through the riverbank "<< direction << std::endl;
}

void RiverbankArtillery::fight(Direction direction) {
     Artillery::fight(direction);
    std::cout << "Artillery attacks from the riverbank " << direction << std::endl;
}

void RiverbankCavalry::fight(Direction direction) {
    Cavalry::fight(direction);
    std::cout << "Cavalry attacks from the riverbank " << direction << std::endl;
}

void RiverbankInfantry::fight(Direction direction) {
    Infantry::fight(direction);
    std::cout << "Infantry attacks from the riverbank " << direction << std::endl;
}

UnitComponent * RiverbankCavalry::clone() {
    return new RiverbankCavalry(*this);
}

UnitComponent * RiverbankArtillery::clone() {
    return new RiverbankArtillery(*this);
}

UnitComponent * RiverbankInfantry::clone() {
    return new RiverbankInfantry(*this);
}