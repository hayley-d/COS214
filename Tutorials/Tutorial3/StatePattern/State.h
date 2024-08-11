#ifndef STATEPATTERN_STATE_H
#define STATEPATTERN_STATE_H

#include "Player.h"
class Player;

class State {
public:
    virtual void update(Player* player) =0;
    virtual ~State();
};


#endif //STATEPATTERN_STATE_H
