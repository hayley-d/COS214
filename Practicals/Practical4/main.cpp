#include <iostream>

#include "Barn.h"
#include "CropField.h"
#include "DrySoil.h"
#include "Farm.h"
#include "FertilizerDecorator.h"
#include "FertilizerTruck.h"
#include "LogisticsTruck.h"
#include "StorageDecorator.h"

int main() {
    //no problems with construction
    CropField field1(100,12,CropType::Soybeans);
    Barn barn1(100,12,CropType::Soybeans);
    Farm farm1(CropType::Soybeans);

    std::shared_ptr<FarmUnit> farm_unit1 = std::make_shared<CropField>(100,12,Soybeans);
    //add does not cause leaks :)
    farm1.addFarmUnit(farm_unit1);
    field1.addFarmUnit(farm_unit1);

    //also good
    std::cout << "Length of vector: " << farm1.getChildren().size() << std::endl;
    std::cout << "Length of vector: " << field1.getChildren().size() << std::endl;


    std::cout << "Current Area: " << farm1.getSurfaceArea() <<std::endl;
    std::cout << "Current Area: " << field1.getSurfaceArea() <<std::endl;
    std::cout << "Current Area: " << barn1.getSurfaceArea() <<std::endl;


    std::cout << "Total Capacity: " << farm1.getTotalcapacity() <<std::endl;
    std::cout << "Total Capacity: " << field1.getTotalcapacity() <<std::endl;
    std::cout << "Current Area: " << barn1.getTotalcapacity() <<std::endl;

    std::cout << "Original Soil State: " << farm1.getSoilStateName() <<std::endl;
    std::cout << "Original Soil State: " << field1.getSoilStateName() <<std::endl;
    std::cout << "Original Soil State: " << barn1.getSoilStateName() <<std::endl;

    farm1.fertilizeCrops();
    field1.fertilizeCrops();
    barn1.fertilizeCrops();

    farm1.harvestWithBonus();
    field1.harvestWithBonus();
    barn1.harvestWithBonus();

    farm1.makeItRain();
    field1.makeItRain();
    barn1.makeItRain();

    farm1.fertilizeCrops();
    field1.fertilizeCrops();
    barn1.fertilizeCrops();

    farm1.harvestWithBonus();
    field1.harvestWithBonus();
    barn1.harvestWithBonus();

    /*std::cout << "Soil State: " << farm1.getSoilStateName() <<std::endl;
    std::cout << "Soil State: " << field1.getSoilStateName() <<std::endl;
    std::cout << "Current Area: " << barn1.getSoilStateName() <<std::endl;
    */

    farm1.makeItRain();
    field1.makeItRain();
    barn1.makeItRain();

    /*std::cout << "Soil State: " << farm1.getSoilStateName() <<std::endl;
    std::cout << "Soil State: " << field1.getSoilStateName() <<std::endl;
    std::cout << "Current Area: " << barn1.getSoilStateName() <<std::endl;*/

    farm1.heatWave();
    field1.heatWave();
    barn1.heatWave();

    farm1.harvestWithBonus();
    field1.harvestWithBonus();
    barn1.harvestWithBonus();

    farm1.fertilizeCrops();
    field1.fertilizeCrops();
    barn1.fertilizeCrops();

    /*std::cout << "Soil State: " << farm1.getSoilStateName() <<std::endl;
    std::cout << "Soil State: " << field1.getSoilStateName() <<std::endl;
    std::cout << "Current Area: " << barn1.getSoilStateName() <<std::endl;*/

    farm1.heatWave();
    field1.heatWave();
    barn1.heatWave();

    farm1.makeItRain();
    field1.makeItRain();
    barn1.makeItRain();

    /*std::cout << "Soil State: " << farm1.getSoilStateName() <<std::endl;
    std::cout << "Soil State: " << field1.getSoilStateName() <<std::endl;
    std::cout << "Current Area: " << barn1.getSoilStateName() <<std::endl;*/

    std::cout << "Crop: " << farm1.getCropType().crop <<std::endl;
    std::cout << "Crop: " << field1.getCropType().crop <<std::endl;

    farm1.printFarm();
    field1.printFarm();

    //getCurrentStorageCapacity
    std::cout << "Current Capacity: " << farm1.getCurrentStorageCapacity() <<std::endl;
    std::cout << "Current Capacity: " << field1.getCurrentStorageCapacity() <<std::endl;

    //hasStorageSpace
    std::cout << "Storage??: " << (farm1.hasStorageSpace(1) ? "true" : "false" )<<std::endl;
    std::cout << "Storage??: " << (field1.hasStorageSpace(1) ? "true" : "false" )<<std::endl;

    Truck* truck1 = new FertilizerTruck(farm1);
    Truck* truck2 = new FertilizerTruck(farm1);
    Truck* truck3 = new LogisticsTruck(farm1);
    Truck* truck4 = new LogisticsTruck(farm1);

    Truck* truck5 = new FertilizerTruck(field1);
    Truck* truck6 = new FertilizerTruck(field1);

    Truck* truck7 = new FertilizerTruck(barn1);
    Truck* truck8 = new FertilizerTruck(barn1);

    //no leaks with this it all works out :)
    farm1.buyTruck(*truck1);
    farm1.buyTruck(*truck2);
    farm1.buyTruck(*truck3);
    farm1.buyTruck(*truck4);
    field1.buyTruck(*truck5);
    field1.buyTruck(*truck6);
    barn1.buyTruck(*truck8);
    barn1.buyTruck(*truck7);

    farm1.callTruck(Event::SOIL_CHANGE);
    field1.callTruck(Event::SOIL_CHANGE);
    barn1.callTruck(Event::SOIL_CHANGE);

    farm1.callTruck(Event::STORAGE_FULL);
    field1.callTruck(Event::STORAGE_FULL);
    barn1.callTruck(Event::STORAGE_FULL);

    farm1.sellTruck(*truck1);
    farm1.sellTruck(*truck2);
    field1.sellTruck(*truck5);
    barn1.sellTruck(*truck8);

    delete truck1;
    delete truck2;
    delete truck5;
    delete truck8;

    farm1.removeFarmUnit(farm_unit1);
    field1.removeFarmUnit(farm_unit1);

    farm1.removeFarmUnit(farm_unit1);
    field1.removeFarmUnit(farm_unit1);

    CropField* myField = new CropField(200,200,Sugarcane);
    std::shared_ptr<CropField> myField3 = std::make_shared<CropField>(200,200,Sugarcane);

    myField->heatWave();
    FertilizerDecorator sd(*myField);
    std::cout << "Soil State: " << myField->getSoilStateName() <<std::endl;
    sd.applyEnhancement();
    sd.applyEnhancement();

    CropField* myField2 = new CropField(200,200,Sugarcane);

    StorageDecorator sdd(*myField2);
    sdd.applyEnhancement();


    Barn b1(100,100,CropType::Corn);
    std::cout << b1.getCropType().crop << std::endl;
    Barn b2(100,100,CropType::Soybeans);
    std::cout << b2.getCropType().crop << std::endl;
    Barn b3(100,100,CropType::Sugarcane);
    std::cout << b3.getCropType().crop << std::endl;
    Barn b4(100,100,CropType::Wheat);
    std::cout << b4.getCropType().crop << std::endl;



    return 0;
}
