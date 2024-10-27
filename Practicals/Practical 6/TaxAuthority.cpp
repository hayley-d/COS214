#include "TaxAuthority.h"

TaxAuthority::TaxAuthority(){
    this->strategy = std::make_unique<FlatTaxStrategy>();
    this->current_citizen_tax = 0;
    this->current_building_tax = 0;
}

TaxAuthority::~TaxAuthority(){
    //Nothing yet unless I have to change from smart pointers :)
}

void TaxAuthority::registerBuilding(std::shared_ptr<Building> building) {
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

void TaxAuthority::notifyBuildings(int amount) {
    while(this->buildings->hasNext()) {
        this->buildings->getBuilding()->
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

void TaxAuthority::changeRate(int percentage) {
    // Do not think this is needed?
}
