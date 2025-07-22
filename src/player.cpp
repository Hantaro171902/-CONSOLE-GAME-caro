#include "player.h"

using namespace std;

Player::Player(CellState type, const string& name) 
    : playerType(type), playerName(name) {}

CellState Player::getType() const {
    return playerType;
}

void Player::setName(const string& newName) {
    playerName = newName;
}

string Player::getName() const {
    return playerName;
}

int Player::getScore() const {
    return score;
}

void Player::incrementScore() {
    score++;
}

void Player::resetScore() {
    score = 0;
}

int Player::getTime() const {
    return timeTaken;
}

void Player::addTime(int seconds) {
    timeTaken += seconds;
}

void Player::resetTime() {
    timeTaken = 0;
}
