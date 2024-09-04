#include "LogisticsTruck.h"

void LogisticsTruck::startEngine(Event e) {
    if(e == Event::STORAGE_FULL) {
        this->subject->collectCrops();
    }
}
