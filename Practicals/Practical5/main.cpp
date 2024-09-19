#include "SmartDevice.h"
#include "SmartThermostat.h"
#include "SmartDoor.h"
#include <iostream>
#include "SmartLight.h"
#include "Event.h"
#include "DeviceType.h"
#include <memory>
int main() {
    // Test SmartLight
    std::shared_ptr<SmartLight> device1 = std::make_shared<SmartLight>(1,100); 
    std::shared_ptr<SmartLight> device2 = std::make_shared<SmartLight>(2); 
    
    if(device1->getId() == 1 && device2->getId() == 2) {
        std::cout << "Test 0 Passed" << std::endl;
    }

    //Test light functions
    if(device1->getIntensity() == 100 && device2->getIntensity() == 0) {
        std::cout << "Test 1 Passed" << std::endl;
    }

    device1->toggle();
    device2->toggle();
    if(device1->getIntensity() == 0 && device2->getIntensity() == 100) {
        std::cout << "Test 2 Passed" << std::endl;
    }

    device1->toggleOn();
    device2->toggleOn();
    if(device1->getIntensity() == 100 && device2->getIntensity() == 100) {
        std::cout << "Test 3 Passed" << std::endl;
    }

    device1->toggleOn();
    device2->toggleOn();
    if(device1->getIntensity() == 100 && device2->getIntensity() == 100) {
        std::cout << "Test 4 Passed" << std::endl;
    }

    device1->toggleOff();
    device2->toggleOff();
    if(device1->getIntensity() == 0 && device2->getIntensity() == 0) {
        std::cout << "Test 5 Passed" << std::endl;
    }

    device1->toggleOff();
    device2->toggleOff();
    if(device1->getIntensity() == 0 && device2->getIntensity() == 0) {
        std::cout << "Test 6 Passed" << std::endl;
    }

    device1->setIntensity(50);
    device2->setIntensity(20);
    if(device1->getIntensity() == 50 && device2->getIntensity() == 20) {
        std::cout << "Test 7 Passed" << std::endl;
    }

    device2->toggle();
    if(device1->getStatus() == "Light is on" && device2->getStatus() == "Light is off") {
        std::cout << "Test 8 Passed" << std::endl;
    }

    if(device1->getDeviceType() == DeviceType::Light && device2->getDeviceType() == DeviceType::Light) {
        std::cout << "Test 9 Passed" << std::endl;
    }

    //Test the DeviceType enum
    std::cout << DeviceType::Light << std::endl;
    std::cout << DeviceType::Thermostat << std::endl;
    std::cout << DeviceType::Door << std::endl;
    
    std::shared_ptr<SmartDoor> device3 = std::make_shared<SmartDoor>(3); 
    std::shared_ptr<SmartDoor> device4 = std::make_shared<SmartDoor>(4); 

    if(device3->getId() == 3 && device4->getId() == 4) {
        std::cout << "Test 1 Passed" << std::endl;
    }

    device4->toggle();
    if(device3->getStatus() == "Door is unlocked" && device4->getStatus() == "Door is locked") {
        std::cout << "Test 2 Passed" << std::endl;
    }

    device3->toggle();
    device4->toggle();
    if(device3->isLocked() && !device4->isLocked()) {
        std::cout << "Test 3 Passed" << std::endl;
    }

    device3->toggleOn();
    device4->toggleOn();
    if(device3->isLocked() && device4->isLocked()) {
        std::cout << "Test 4 Passed" << std::endl;
    }

    device3->toggleOn();
    device4->toggleOn();
    if(device3->isLocked() && device4->isLocked()) {
        std::cout << "Test 5 Passed" << std::endl;
    }

    device3->toggleOff();
    device4->toggleOff();
    if(!device3->isLocked() && !device4->isLocked()) {
        std::cout << "Test 6 Passed" << std::endl;
    }

    device3->toggleOff();
    device4->toggleOff();
    if(!device3->isLocked() && !device4->isLocked()) {
        std::cout << "Test 7 Passed" << std::endl;
    }

    if(device3->getDeviceType() == DeviceType::Door && device4->getDeviceType() == DeviceType::Door) {
        std::cout << "Test 8 Passed" << std::endl;
    }
 
    std::shared_ptr<SmartThermostat> device5 = std::make_shared<SmartThermostat>(5); 
    std::shared_ptr<SmartThermostat> device6 = std::make_shared<SmartThermostat>(6,15); 

    if(device5->getId() == 5 && device6->getId() == 6) {
        std::cout << "Test 1 Passed" << std::endl;
    }

    if(device5->getTemperature() == 0 && device6->getTemperature() == 15) {
        std::cout << "Test 2 Passed" << std::endl;
    }

    device5->setTemperature(20);
    device6->setTemperature(20);
    if(device5->getTemperature() == 20 && device6->getTemperature() == 20) {
        std::cout << "Test 3 Passed" << std::endl;
    }

    if(device5->getDeviceType() == DeviceType::Thermostat && device6->getDeviceType() == DeviceType::Thermostat) {
        std::cout << "Test 4 Passed" << std::endl;
    }

    if(device5->getStatus() == "Thermostat is off" && device6->getStatus() == "Thermostat is off") {
        std::cout << "Test 5 passed" <<std::endl;
    }

    device5->toggle();
    device6->toggle();
    if(device5->getStatus() == "Thermostat is on" && device6->getStatus() == "Thermostat is on") {
        std::cout << "Test 6 passed" <<std::endl;
    }

    device5->toggle();
    device6->toggle();
    if(!device5->isOn() && !device6->isOn()) {
        std::cout << "Test 7 Passed" <<std::endl;
    }

    device5->toggleOn();
    device6->toggleOn();
    if(device5->isOn() && device6->isOn()) {
        std::cout << "Test 8 Passed" <<std::endl;
    }

    device5->toggleOff();
    device6->toggleOff();
    if(!device5->isOn() && !device6->isOn()) {
        std::cout << "Test 9 Passed" <<std::endl;
    }

    return 0;
}
