//
// Created by User-PC on 11/08/2024.
//

#include "DeadState.h"

void DeadState::update(Player *player) {
    player->performAction("dead");
}
