// player.cpp
#include "player.h"
#include <iostream>

using namespace std;

Player::Player(CellState type, const string& name) 
: playerType(type), playerName(name) {}

CellState Player::getType() const {
    return playerType;
}

string Player::getName() const {
    return playerName;
}

void Player::setName(const string& newName) {
    playerName = newName;
}

void Player::displayInfo() const {
    cout << "Player: " << playerName << " (";
    if (playerType == CellState::PLAYER_X) {
        cout << "X";
    } else {
        cout << "O";
    }
    cout << ")" << endl;
}
