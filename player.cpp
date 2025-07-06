#include "player.h"

using namespace std;

Player::Player(CellState type, const string& name) : playerType(type), playerName(name) {}

CellState Player::getType() const {
    return playerType;
}

void Player::setName(const string& newName) {
    playerName = newName;
}

string Player::getName() const {
    return playerName;
}
