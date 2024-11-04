#include "ServiceFactory.h"
#include "Building.h"
#include "Service.h"
#include "PoliceService.h"
#include "HealthService.h"
#include "EducationService.h"
#include <string>

// Made citizen a reference instead of pointer to prevent it being nullptr
Building *ServiceFactory::createBuilding(const std::string& name,BuildingType type, Citizen& owner) {
    Resources* resources = new Resources(200,200,false);
    std::string location = "City Center";

    if(type == BuildingType::PoliceStation) {
        int id = numberOfPoliceStations;
        numberOfPoliceStations++;
        Building* b = new PoliceService(name,300, location,resources, 300, owner, id, BuildingType::PoliceStation);
        taxAuthority->registerBuilding(*b);
        return b; 
    } else if(type == BuildingType::Hospital) {
        int id = numberOfHospitals;
        numberOfHospitals++;
        Building* b = new HealthService(name,500, location,resources, 500, owner,BuildingType::Hospital,id);
        taxAuthority->registerBuilding(*b);
        return b; 

    } else {
        int id = numberOfSchools;
        numberOfSchools++;
        Building* b = new EducationService(name,200, location,resources, 1000, owner, id,BuildingType::School);
        taxAuthority->registerBuilding(*b);
        return b; 
    }
}
