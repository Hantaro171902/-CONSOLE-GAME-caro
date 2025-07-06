#pragma once

#include "board.h"

class Player {
private:
    CellState playerType; // Player type (X or O)

public:
    Player(CellState type) : playerType(type) {}

    CellState getType() const {
        return playerType;
    }   

    // TODO 
    // Display player information    
};