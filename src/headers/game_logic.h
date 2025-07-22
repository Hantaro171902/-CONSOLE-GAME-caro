#pragma once

#include "board.h"
#include "player.h"
#include "menu.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include "move_record.h"

using namespace std;
using namespace std::chrono;

class Game {
private:
    steady_clock::time_point startTime; // Start time for the game
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
    int moveHistoryScroll = 0;

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

