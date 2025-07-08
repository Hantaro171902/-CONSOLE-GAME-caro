#pragma once

#include "board.h"
#include <string>

class Player {
private:
    CellState playerType;
    string playerName;
    int score = 0; // Player's score

public:
    Player(CellState type, const string& name = "");
    
    CellState getType() const;
    void setName(const string& newName);
    string getName() const;

    int getScore() const;   // Get player's score
    void incrementScore();  // Increment player's score by 1
    void resetScore();      // Reset player's score to 0
};
