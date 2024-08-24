#ifndef WARARCHIVES_H
#define WARARCHIVES_H

#include "TacticalMemento.h"
#include <map>
#include <string>

class WarArchives {
private:
    std::map<std::string, TacticalMemento*> mementoMap;

public:
    ~WarArchives();

    void addTacticalMemento(TacticalMemento* memento, const std::string& label);
    void removeTacticalMemento(const std::string& label);
    TacticalMemento* getMemento(const std::string& label);
};


#endif //WARARCHIVES_H
