#pragma once

#include "board.h"
#include "player.h"
#include "menu.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct MoveRecord {
    int row; // Row of the move
    int col; // Column of the move
    CellState player; // Player who made the move
};

class Game {
private:
    chrono::steady_clock::time_point startTime; // Start time for the game
    int timeX; // Time taken by Player X
    int timeO; // Time taken by Player O
    
    Board board;
    Player playerX;
    Player playerO;
    Player* currentPlayer;
    bool isRunning;
    Menu menu; 

    int cursorRow = 0; // Cursor position for input
    int cursorCol = 0; // Cursor position for input

    vector<MoveRecord> moveHistory; // History of moves made in the game

public:
    Game();
    void init();
    void run();
    // void processInput();
    // void update();
    void render();
    void switchTurn();
    void handleMove();
    // void displayInstructions();
    void displayWinner();
    bool running() const {
        return isRunning;
    };
    void resetGame();

};

