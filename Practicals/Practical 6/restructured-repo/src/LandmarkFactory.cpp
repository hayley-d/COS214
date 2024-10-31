#include "LandmarkFactory.h"
#include "Landmark.h"
#include <string>


Building *LandmarkFactory::createBuilding(BuildingType type, Citizen& owner) {
    Resources* resources = new Resource(0,0,false);
    int cost;
    std::string location = "City center";
    int size = 2000;

    if(type == BuildingType::Statue) {
        cost = 1000;
    } else if(type == BuildingType::Park) {
        cost = 1200;
    } else {
        cost = 3000;
    }
    return new Landmark(cost,location,*resources,size,owner,type);
}
