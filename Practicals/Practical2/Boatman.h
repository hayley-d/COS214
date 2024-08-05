#ifndef BOATMAN_H
#define BOATMAN_H

#include "Soldiers.h"

class Boatman : public Soldiers{
public:
    Boatman();
    ~Boatman() override;

    void vivificaMemento(ConcreteMemento &mem) override;

    ConcreteMemento * militusMemento() override;
};



#endif //BOATMAN_H
