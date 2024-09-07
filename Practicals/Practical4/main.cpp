#include <iostream>

#include "Barn.h"
#include "CropField.h"
#include "DrySoil.h"
#include "Farm.h"

int main() {
    //no problems with construction
    CropField field1(12,12,CropType::Soybeans);
    Barn barn1(12,12,CropType::Soybeans);
    Farm farm1(CropType::Soybeans);

    std::shared_ptr<FarmUnit> farm_unit1 = std::make_shared<CropField>(12,12,Soybeans);
    //add does not cause leaks :)
    farm1.addFarmUnit(farm_unit1);
    field1.addFarmUnit(farm_unit1);

    //also good
    std::cout << "Length of vector: " << farm1.getChildren().size() << std::endl;
    std::cout << "Length of vector: " << field1.getChildren().size() << std::endl;


    std::cout << "Current Area: " << farm1.getSurfaceArea() <<std::endl;
    std::cout << "Current Area: " << field1.getSurfaceArea() <<std::endl;


    std::cout << "Total Capacity: " << farm1.getTotalcapacity() <<std::endl;
    std::cout << "Total Capacity: " << field1.getTotalcapacity() <<std::endl;

    std::cout << "Soil State: " << farm1.getSoilStateName() <<std::endl;
    std::cout << "Soil State: " << field1.getSoilStateName() <<std::endl;

    farm1.makeItRain();
    field1.makeItRain();

    std::cout << "Soil State: " << farm1.getSoilStateName() <<std::endl;
    std::cout << "Soil State: " << field1.getSoilStateName() <<std::endl;

    return 0;
}
