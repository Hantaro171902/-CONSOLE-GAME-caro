#include "board.h"
#include <iomanip>
#include "ultils.h"
#include <iostream>

using namespace std;

// int board[BOARD_SIZE][BOARD_SIZE] = {0}; 

Board::Board() {
    grid.resize(BOARD_SIZE, vector<CellState>(BOARD_SIZE, CellState::EMPTY));
}

void Board::draw(int cursorRow, int cursorCol) const {
    clearScreen();

    // Print column headers
    cout << "    ";
    for (int col = 1; col <= BOARD_SIZE; col++) {
        cout << setw(3) << col << " ";
    }
    cout << endl;

    for (int y = 0; y <= 2 * BOARD_SIZE; y++) {
        // Print row numbers
        if (y % 2 == 1) {
            cout << setw(3) << (y / 2 + 1) << " ";
        } else {
            cout << "    ";
        }

        for (int x = 0; x <= 4 * BOARD_SIZE; x++) {
            bool isBorderRow = (y == 0 || y == 2 * BOARD_SIZE);
            bool isBorderCol = (x == 0 || x == 4 * BOARD_SIZE);

            if (y % 2 == 0) { // Horizontal lines
                if (x % 4 == 0) {
                    // Corners and border junctions
                    if (isBorderRow && isBorderCol) {
                        cout << (y == 0
                                 ? (x == 0 ? SYMBOL_DOUBLE_TOP_LEFT : SYMBOL_DOUBLE_TOP_RIGHT)
                                 : (x == 0 ? SYMBOL_DOUBLE_BOTTOM_LEFT : SYMBOL_DOUBLE_BOTTOM_RIGHT));
                    } else if (isBorderRow) {
                        cout << (y == 0 ? SYMBOL_DOUBLE_T_TOP : SYMBOL_DOUBLE_T_BOTTOM);
                    } else if (isBorderCol) {
                        cout << (x == 0 ? SYMBOL_DOUBLE_T_LEFT : SYMBOL_DOUBLE_T_RIGHT);
                    } else {
                        cout << SYMBOL_INTERSECT;
                    }
                } else {
                    // Horizontal lines
                    cout << (isBorderRow ? SYMBOL_DOUBLE_HORIZONTAL : SYMBOL_HORIZONTAL);
                }
            } else { // Vertical lines and cells
                if (x % 4 == 0) {
                    cout << (isBorderCol ? SYMBOL_DOUBLE_VERTICAL : SYMBOL_VERTICAL);
                } else {
                    int row = (y - 1) / 2;
                    int col = (x - 1) / 4;
                    if ((x - 2) % 4 == 0 && row < BOARD_SIZE && col < BOARD_SIZE) {
                        bool isCursor = (row == cursorRow && col == cursorCol);

                        if (isCursor) cout << "\033[7m"; // Invert colors for cursor

                        CellState val = grid[row][col];
                        if (val != CellState::EMPTY) {
                            if (val == CellState::PLAYER_X) {
                                setTextColor(34); // Blue
                                cout << "X";
                            } else if (val == CellState::PLAYER_O) {
                                setTextColor(31); // Red
                                cout << "O";
                            }
                            setTextColor(7); // Reset color
                        } else {
                            cout << " ";
                        }

                        if (isCursor) cout << "\033[0m"; // Reset colors for cursor
                    } else {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;

      

    }
    // Move real terminal cursor to blinking cell
    int termY = 2 + cursorRow * 2;      // +2 for header offset
    int termX = 5 + cursorCol * 4;      // +5 for padding/row label
    gotoXY(termX, termY);
    cout << "\033[?25h"; // Show the terminal cursor
    cout.flush();
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

    // Check in the positive direction
    for (int i = 1; i < WINNING_COUNT; i++) {
        int r = row - i * dRow;
        int c = col - i * dCol;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && grid[r][c] == player) {
            count++;
        } else {
            break;
        }
    }

    // Check in the negative direction
    for (int i = 1; i < WINNING_COUNT; i++) {
        int r = row + i * dRow;
        int c = col + i * dCol;
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