#ifndef UNITCOMPONENT_H
#define UNITCOMPONENT_H

class UnitComponent {
public:
    virtual void move() = 0;
    virtual void fight() = 0;
    virtual bool add(UnitComponent& component)=0;
    virtual bool remove(UnitComponent& component)=0;
    virtual ~UnitComponent() = default;
};



#endif //UNITCOMPONENT_H
