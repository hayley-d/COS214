#ifndef ITERATOR_H
#define ITERATOR_H
#include "FarmUnit.h"

class Iterator {
public:
    virtual FarmUnit* firstFarm() = 0;
    virtual FarmUnit* currentFarm() = 0;
    virtual bool isDone() = 0 ;
    virtual FarmUnit* next() = 0;
    virtual ~Iterator() = default;
};

#endif //ITERATOR_H
