#ifndef STATEPATTERN_DEADSTATE_H
#define STATEPATTERN_DEADSTATE_H
#include "State.h"

class DeadState : public State{
public:
    void update(Player* player) override;
};


#endif //STATEPATTERN_DEADSTATE_H
