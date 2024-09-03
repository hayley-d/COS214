#ifndef FARMCOMPOSITE_H
#define FARMCOMPOSITE_H
#include <vector>

#include "FarmUnit.h"
class FarmComposite : public FarmUnit {
public:
    virtual void addFarmUnit(FarmUnit* unit) = 0;
    virtual void removeFarmUnit(FarmUnit * unit) = 0;
    virtual std::vector<FarmUnit*>& getFarms();


};
#endif //FARMCOMPOSITE_H
