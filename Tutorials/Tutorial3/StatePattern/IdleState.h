#ifndef STATEPATTERN_IDLESTATE_H
#define STATEPATTERN_IDLESTATE_H
#include "State.h"

class IdleState : public State{
public:
    void update(Player* player);
};


#endif //STATEPATTERN_IDLESTATE_H
