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
                    cout << " ";
                }
            } else { // Vertical lines
                if (x % 2 == 0) {
                    cout << BOX_VERTICAL;
                } else {
                    int cellValue = board[y / 2][x / 2];
                    if (cellValue == 1) {
                        setTextColor(ANSI_FOREGROUND_COLORS[1]); // Player X
                        cout << "X";
                        setTextColor(ANSI_FOREGROUND_COLORS[0]); // Reset color
                    } else if (cellValue == 2) {
                        setTextColor(ANSI_FOREGROUND_COLORS[2]); // Player O
                        cout << "O";
                        setTextColor(ANSI_FOREGROUND_COLORS[0]); // Reset color
                    } else {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}