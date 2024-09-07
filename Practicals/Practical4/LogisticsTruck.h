#ifndef LOGISTICSTRUCK_H
#define LOGISTICSTRUCK_H

#include "Truck.h"

class LogisticsTruck : public Truck{
public:
    void startEngine(Event e) override;
    LogisticsTruck(FarmUnit& farmUnit){
        this->subject = &farmUnit;
    }
};

#endif //LOGISTICSTRUCK_H
