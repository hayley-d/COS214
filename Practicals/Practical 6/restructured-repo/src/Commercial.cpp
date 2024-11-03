#include "Commercial.h"

Commercial::Commercial(int cost, std::string& location, Resources* resources, int size, Citizen& owner,BuildingType name, int max, int rate) : Building(cost, location, resources, size, owner , name) {
    this->maxEmployees = max;
    this->productionRate = rate;
}


int Commercial::produceMoney() {
    return 100;
}

void Commercial::employ(Citizen& employee) {
    if(!employee.getEmploymentStatus() && employees.size() < maxEmployees) {
        employees.push_back(employee.getId());
        employee.setWork(*this);
    }

}

int Commercial::pay() {
    return 3700;
}

void Commercial::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.fired();
    }   
}

void Commercial::retire(Citizen& employee) {
    auto it = find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.retireToCountryside();
    }
}

int Commercial::getProductionRate() {
    return productionRate;
}

int Commercial::getNumberOfEmployees() {
    return employees.size();
}

int Commercial::getMaxEmployees() {
    return maxEmployees;
}
