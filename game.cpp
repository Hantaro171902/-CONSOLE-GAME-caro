#include "game.h"
#include "ultils.h"
#include "board.h"
#include <iostream>

Game::Game() : currentPlayer(CellState::PLAYER_X), isRunning(true) {}

void Game::run() {
    board.reset();
    while (isRunning) {
        board.draw();
        cout << "Player " << (currentPlayer == CellState::PLAYER_X ? "X" : "O") << "'s turn. " << endl;

        int row, col;
        cout << "Enter row (0-" << BOARD_SIZE - 1 << "): ";
        cin >> row;
        cout << "Enter column (0-" << BOARD_SIZE - 1 << "): ";
        cin >> col;

        if (!board.placeMove(row, col, currentPlayer)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (board.checkWin(row, col, currentPlayer)) {
            board.draw();
            // displayWinner();
            cout << "Player " << (currentPlayer == CellState::PLAYER_X ? "X" : "O") << " wins!" << endl;
            isRunning = false;
            break;
        } 

        switchPlayer();
    }
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == CellState::PLAYER_X) ? CellState::PLAYER_O : CellState::PLAYER_X;
}

void Game::displayWinner() {
    // This function can be used to display the winner in a more elaborate way
    cout << "Game Over!" << endl;
    cout << "Player " << (currentPlayer == CellState::PLAYER_X ? "X" : "O") << " wins!" << endl;
}