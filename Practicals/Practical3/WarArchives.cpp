#include "WarArchives.h"
WarArchives::~WarArchives() {
    for (auto& pair : mementoMap) {
        delete pair.second;
    }
}

void WarArchives::addTacticalMemento(TacticalMemento* memento, const std::string& label) {
    mementoMap[label] = memento;
}

void WarArchives::removeTacticalMemento(const std::string& label) {
    delete mementoMap[label];
    mementoMap.erase(label);
}

TacticalMemento* WarArchives::getMemento(const std::string& label) {
    return mementoMap[label];
}