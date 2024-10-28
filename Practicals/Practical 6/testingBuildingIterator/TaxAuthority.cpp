#include "TaxAuthority.h"

TaxAuthority::TaxAuthority(){
    this->buildings = std::make_unique<BuildingCollection>();
    this->strategy = std::make_unique<FlatTaxStrategy>();
}

void TaxAuthority::registerBuilding(std::shared_ptr<Building> building) {
    std::cout << "Registering a new building\n";
    this->buildings->addBuilding(building);
}

void TaxAuthority::registerCitizen(std::shared_ptr<Citizen> citizen) {
    this->citizens.push_back(citizen);
}

void TaxAuthority::notifyCitizens(int amount) {
    for(auto c : this->citizens) {
        c->payTax(calculateCitizenTax(c->getFunds()));
    }
}

void TaxAuthority::notifyBuildings() {
    int counter = 0;
    for(auto it = buildings->begin(); it != buildings->end(); ++it) {
        counter++;
        auto building = *it;
        std::cout << "Building b" << counter << " paying tax\n";
        building->payTax(calculateBuildingTax(building->getCost()));
    }
}

void TaxAuthority::setStrategy(std::unique_ptr<TaxStrategy> taxStrategy) {
    this->strategy = std::move(taxStrategy);
}

int TaxAuthority::calculateBuildingTax(int value) {
    return this->strategy->calculateBuildingTax(value);
}

int TaxAuthority::calculateCitizenTax(int earnings) {
    return this->strategy->calculateCitizenTax(earnings);
}

