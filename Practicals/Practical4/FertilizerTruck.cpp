#include "FertilizerTruck.h"

void FertilizerTruck::startEngine(Event e) {
    if(e == Event::SOIL_CHANGE)
        this->subject->fertilizeCrops();
}
