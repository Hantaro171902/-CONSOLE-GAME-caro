#pragma once

#include "board.h"
#include "player.h"
#include "menu.h"

class Game {
private:
    Board board;
    Player playerX;
    Player playerO;
    Player* currentPlayer;
    bool isRunning;
    Menu menu; 
    
    int cursorRow = 0; // Cursor position for input
    int cursorCol = 0; // Cursor position for input

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

