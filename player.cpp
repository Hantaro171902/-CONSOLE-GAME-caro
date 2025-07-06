// player.cpp
#include "player.h"

Player::Player(CellState type) : playerType(type) {}

CellState Player::getType() const {
    return playerType;
}
