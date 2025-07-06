#pragma once

#include "board.h"
#include "player.h"

class Game {
private:
    Board board;
    Player playerX;
    Player playerO;
    Player* currentPlayer;
    bool isRunning;

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

