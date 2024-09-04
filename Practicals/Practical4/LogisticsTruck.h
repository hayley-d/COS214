#ifndef LOGISTICSTRUCK_H
#define LOGISTICSTRUCK_H

#include "Truck.h"

class LogisticsTruck : public Truck{
public:
    void startEngine(Event e) override;
};

#endif //LOGISTICSTRUCK_H
