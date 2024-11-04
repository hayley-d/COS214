#include "Factory.h"
#include "Building.h"

void Factory::fire(Citizen& employee) {
    auto it = std::find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.fired();
    }   
}

void Factory::retire(Citizen& employee) {
    auto it = find(employees.begin(), employees.end(), employee.getId());

    if(it != employees.end()) {
        employees.erase(it);
        employee.retireToCountryside();
    }
}

void Factory::employ(Citizen& employee) {
    if(!employee.getEmploymentStatus() && employees.size() < maxEmployees) {
        employees.push_back(employee.getId());
        employee.setWork(*this);
    }
}

std::vector<int>& Factory::getEmployees() {
    return employees;
}
