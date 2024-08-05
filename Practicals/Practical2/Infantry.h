#ifndef INFANTRY_H
#define INFANTRY_H

#include "Soldiers.h"

class Infantry : public Soldiers{
public:
    Infantry();
    ~Infantry() override;

    ConcreteMemento * militusMemento() override;
};



#endif //INFANTRY_H
