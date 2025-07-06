#pragma once

#include "board.h"
#include <string>

class Player {
private:
    CellState playerType;
    string playerName;

public:
    Player(CellState type, const string& name = "");
    CellState getType() const;
    void setName(const string& newName);
    string getName() const;
};
