#pragma once

#include "board.h"

class Game {
private:
    Board board;
    CellState currentPlayer;
    
public:
    Game();
    void run();
    // void processInput();
    // void update();
    // void render();
private :
    void switchPlayer();
    void handleTurn();
    // void displayInstructions();
    void displayWinner();
    // void resetGame();
};

