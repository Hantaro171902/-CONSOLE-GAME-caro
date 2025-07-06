// game_logic.cpp
#include "game_logic.h"
#include "ultils.h"
#include <iostream>

using namespace std;

Game::Game() : playerX(CellState::PLAYER_X), playerO(CellState::PLAYER_O), isRunning(false) {
    currentPlayer = &playerX;
}

void Game::init() {
    board.reset();
    currentPlayer = &playerX;
    isRunning = true;
}

void Game::run() {
    while (isRunning) {
        render();
        handleMove();
    }
}

void Game::render() {
    board.draw();
    gotoXY(0, 2 * BOARD_SIZE + 2);
    setTextColor(static_cast<int>(currentPlayer->getType()));
    cout << (currentPlayer->getType() == CellState::PLAYER_X ? "X" : "O") << "'s turn." << endl;
    setTextColor(7);
}

void Game::handleMove() {
    int row, col;
    cout << "Enter row and column (0-based): ";
    cin >> row >> col;

    if (board.placeMove(row, col, currentPlayer->getType())) {
        if (board.checkWin(row, col, currentPlayer->getType())) {
            render();
            displayWinner();
            isRunning = false;
        } else {
            switchTurn();
        }
    } else {
        cout << "Invalid move. Try again." << endl;
    }
}

void Game::switchTurn() {
    currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
}

void Game::displayWinner() {
    gotoXY(0, 2 * BOARD_SIZE + 4);
    setTextColor(static_cast<int>(currentPlayer->getType()));
    cout << (currentPlayer->getType() == CellState::PLAYER_X ? "X" : "O") << " wins!" << endl;
    setTextColor(7);
}

void Game::resetGame() {
    board.reset();
    currentPlayer = &playerX;
    isRunning = true;
}
