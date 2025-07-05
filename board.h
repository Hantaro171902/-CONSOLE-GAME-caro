#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constants for board size
const int BOARD_SIZE = 20; 
const int WINNING_COUNT = 5; // 5 in a row to win

// Symbol for rendering the board
extern const string ANSI_FOREGROUND_COLORS[];
extern const string ANSI_BACKGROUND_COLORS[];
extern const string BOX_TOP_LEFT;
extern const string BOX_TOP_RIGHT;
extern const string BOX_BOTTOM_LEFT;
extern const string BOX_BOTTOM_RIGHT;
extern const string BOX_HORIZONTAL;
extern const string BOX_VERTICAL;
extern const string BOX_T_UP;
extern const string BOX_T_DOWN;
extern const string BOX_T_LEFT;
extern const string BOX_T_RIGHT;
extern const string BOX_CROSS;

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

    void draw() const;
    bool placePiece(int row, int col, CellState player);
    bool checkWin(int row, int col, CellState player) const;
    CellState getCell(int row, int col) const;
    void reset();

};
