#pragma once

#include "board.h"

class Game {
private:
    Board board;
    CellState currentPlayer;
    bool isRunning;

public:
    Game();
    void run();
    // void processInput();
    // void update();
    // void render();
    void switchPlayer();
    void handleTurn();
    // void displayInstructions();
    void displayWinner();
    bool running() const {
        return isRunning;
    };
    // void resetGame();
};

