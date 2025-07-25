#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ultils.h"

using namespace std;

// Constants for board size
const int BOARD_SIZE = 15; 
const int WINNING_COUNT = 5; // 5 in a row to win


enum class CellState {
    EMPTY = 0,
    PLAYER_X = 1,
    PLAYER_O = 2
};

class Board {
private:
    vector<vector<CellState>> grid; 
public:
    Board();

    void draw(int cursorRow, int cursorCol) const;
    bool placeMove(int row, int col, CellState player);
    bool checkWin(int row, int col, CellState player) const;
    bool checkDirection(int row, int col, int dRow, int dCol, CellState player) const;
    CellState getCell(int row, int col) const;
    void reset();

};
