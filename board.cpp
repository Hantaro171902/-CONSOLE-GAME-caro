#include "board.h"
#include <iomanip>
#include "ultils.h"
#include <iostream>

using namespace std;

// int board[BOARD_SIZE][BOARD_SIZE] = {0}; 

Board::Board() {
    grid.resize(BOARD_SIZE, vector<CellState>(BOARD_SIZE, CellState::EMPTY));
}

void Board::draw() const {
    clearScreen();

    // Column headers
    cout << "    ";
    for (int col = 0; col < BOARD_SIZE; col++) {
        int colNumber = col + 1;
        cout << setw(3) << colNumber;
    }
    cout << endl;

    
    for (int y = 0; y <= 2 * BOARD_SIZE; y++) {
        if (y % 2 == 0) { 
            // Row headers
            cout << "   ";
            for (int col = 0; col <= BOARD_SIZE; col++) {
                cout << SYMBOL_INTERSECT << SYMBOL_HORIZONTAL << SYMBOL_HORIZONTAL << SYMBOL_HORIZONTAL;
            }
            cout << endl;
        } else { 
            // Row with cells
            int rowNum = (y - 1) / 2 + 1;
            cout << setw(2) << rowNum << " ";

            for (int x = 0; x <= BOARD_SIZE; ++x) {
                cout << SYMBOL_VERTICAL;

                if (x < BOARD_SIZE) {
                    CellState val = grid[rowNum - 1][x];
                    if (val != CellState::EMPTY) {
                        setTextColor(static_cast<int>(val));
                        cout << " " << (val == CellState::PLAYER_X ? "X" : "O") << " ";
                        setTextColor(7);
                    } else {
                        cout << "   ";
                    }
                }
            }
            cout << endl;
        }
    }
}

bool Board::placeMove(int row, int col, CellState player) {
    if (grid[row][col] == CellState::EMPTY) {
        grid[row][col] = player;
        return true;
    }
    return false;
}

bool Board::checkWin(int row, int col, CellState player) const{
    // Check horizontal, vertical, and both diagonals
    return checkDirection(row, col, 0, 1, player) || // Horizontal
           checkDirection(row, col, 1, 0, player) || // Vertical
           checkDirection(row, col, 1, 1, player) || // Diagonal `
           checkDirection(row, col, 1, -1, player);   // Diagonal /
}

bool Board::checkDirection(int row, int col, int dRow, int dCol, CellState player ) const {
    int count = 1;
    for (int i = 1; i < WINNING_COUNT; i++) {
        int r = row - i * dRow;
        int c = col - i * dCol;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && grid[r][c] == player) {
            count++;
        } else {
            break;
        }
    }
    return count >= WINNING_COUNT;
}

void Board::reset() {
    for (auto& row : grid) {
        fill(row.begin(), row.end(), CellState::EMPTY);
    }
}