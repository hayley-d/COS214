#include "SteelFactory.h"

std::string SteelFactory::getDetails() const {
    std::string details =  "Steel factory: \n";
    details += "Owner: " + owner.getName() + "\n";
    details += "Location: " + location + "\n";
    details += "Employees: " + std::to_string(employees.size()) + "/" + std::to_string(maxEmployees) + "\n";
    details += "Cost: " + std::to_string(cost) + "\n";
    details += "Size: " + std::to_string(size) + "\n";
    return details;
}

int SteelFactory::produceResource() {
    return 100;
}


int SteelFactory::pay() {
    return 163;
}

