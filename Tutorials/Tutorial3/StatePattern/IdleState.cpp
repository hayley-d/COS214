#include "IdleState.h"

void IdleState::update(Player* player) override {
    player->performAction("Standing idle");
}
