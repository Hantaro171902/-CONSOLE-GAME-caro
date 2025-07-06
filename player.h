#pragma once

#include "board.h"
#include <string>

class Player {
private:
    CellState playerType; // Player type (X or O)
    string playerName; // Player name (optional)

public:
    Player(CellState type, const string& name = "") : playerType(type), playerName(name) {}

    CellState getType() const;
    string getName() const;

    void setName(const string& newName) {}
    void displayInfo() const; // Display player information

};