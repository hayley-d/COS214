#include "OpenField.h"

void OpenFieldInfantry::move(Direction direction)  {
    Infantry::move(direction);
    std::cout << "Infantry moves through the fields "<< direction << std::endl;
}

void OpenFieldCavalry::move(Direction direction)  {
    Cavalry::move(direction);
    std::cout << "Cavalry moves through the fields "<< direction << std::endl;
}

void OpenFieldArtillery::move(Direction direction) {
     Artillery::move(direction);
    std::cout << "Artillery moves through the fields "<< direction << std::endl;
}

void OpenFieldInfantry::fight(Direction direction)  {
    Infantry::fight(direction);
    std::cout << "Infantry attacks from the fields " << direction << std::endl;
}

void OpenFieldCavalry::fight(Direction direction)  {
    Cavalry::fight(direction);
    std::cout << "Cavalry attacks from the fields " << direction << std::endl;
}

void OpenFieldArtillery::fight(Direction direction) {
    Artillery::fight(direction);
    std::cout << "Artillery attacks from the fields " << direction << std::endl;
}

UnitComponent * OpenFieldCavalry::clone() {
    return new OpenFieldCavalry(*this);
}

UnitComponent * OpenFieldArtillery::clone() {
    return new OpenFieldArtillery(*this);
}

UnitComponent * OpenFieldInfantry::clone() {
    return new OpenFieldInfantry(*this);
}

OpenFieldInfantry::~OpenFieldInfantry(){}

OpenFieldCavalry::~OpenFieldCavalry(){}

OpenFieldArtillery::~OpenFieldArtillery(){}

