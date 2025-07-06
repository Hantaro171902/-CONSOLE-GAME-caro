#include "board.h"
#include "ultils.h"
#include <iostream>

using namespace std;

int board[BOARD_SIZE][BOARD_SIZE] = {0}; 

void drawBoard() {
    clearScreen();
    for (int y = 0; y <= 2 * BOARD_SIZE; y++) {
        for (int x = 0; x <= 4 * BOARD_SIZE; x++) {
            if (y % 2 == 0) { // Horizontal lines
                if (x % 4 == 0) {
                    cout << SYMBOL_INTERSECT;
                } else {
                    cout << SYMBOL_HORIZONTAL;
                }
            } else { // Vertical lines
                if (x % 4 == 0) {
                    cout << SYMBOL_VERTICAL;    
                } else {
                    int row = (y - 1) / 2;
                    int col = (x - 1) / 4;
                    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && x % 4 == 2) {
                        int val = board[row][col];
                        if (val != 0) {
                            setTextColor(val); // Player X or O
                            cout << (val % 2 == 1 ? "X" : "O");
                            setTextColor(7); // Reset color
                        } else {
                            cout << " ";
                        }
                    } else {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
}

bool placeMove(int row, int col, int player) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0) {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(int row, int col, int player) {
    // Check horizontal, vertical, and both diagonals
    return checkDirection(row, col, 0, 1, player) || // Horizontal
           checkDirection(row, col, 1, 0, player) || // Vertical
           checkDirection(row, col, 1, 1, player) || // Diagonal `
           checkDirection(row, col, 1, -1, player);   // Diagonal /
}

bool checkDirection(int row, int col, int dRow, int dCol, int player) {
    int count = 1;
    for (int i = 1; i < WINNING_COUNT; i++) {
        int r = row - i * dRow;
        int c = col - i * dCol;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == player) {
            count++;
        } else {
            break;
        }
    }
    return count >= WINNING_COUNT;
}