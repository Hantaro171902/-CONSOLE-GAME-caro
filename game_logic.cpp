// game_logic.cpp
#include "game_logic.h"
#include "ultils.h"
#include "cursor_input.h"
#include <chrono>
#include <iomanip>
#include <vector>
#include <string>

#include <iostream>

using namespace std;

Game::Game() : playerX(CellState::PLAYER_X), playerO(CellState::PLAYER_O), isRunning(false) {
    currentPlayer = &playerX;
}

void Game::init() {
    startTime = std::chrono::steady_clock::now();

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
    board.draw(cursorRow, cursorCol);

    // Side menu
    int sideX = 4 * BOARD_SIZE + 10; // Side menu position
    menu.drawRecord(sideX, 2, playerX.getScore(), playerO.getScore(), playerX.getTime(), playerO.getTime());
    menu.drawInstructions(sideX, 12);
    menu.drawMoveHistory(moveHistory, sideX, 20, moveHistoryScroll);


    // Current turn
    gotoXY(0, 2 * BOARD_SIZE + 2);
    setTextColor(static_cast<int>(currentPlayer->getType()));
    cout << (currentPlayer->getType() == CellState::PLAYER_X ? "X" : "O") << "'s turn." << endl;
    setTextColor(7);
}

void Game::handleMove() {
    // int row, col;
    // cout << "Enter row and column: ";
    // cin >> row >> col;
    // row--;
    // col--;

    // if (board.placeMove(row, col, currentPlayer->getType())) {
    //     if (board.checkWin(row, col, currentPlayer->getType())) {
    //         render();
    //         displayWinner();
    //         isRunning = false;
    //     } else {
    //         switchTurn();
    //     }
    // } else {
    //     cout << "Invalid move. Try again." << endl;
    // }

    
    // Handle input for cursor movement and placing moves
    InputKey key = getInputKey();

    // Movment logic based on current player
    if (currentPlayer->getType() == CellState::PLAYER_X) {
        switch (key) {
            case InputKey::UP:  if (cursorRow > 0) cursorRow--; // Move cursor up
                break;
            case InputKey::DOWN: if (cursorRow < BOARD_SIZE - 1) cursorRow++; // Move cursor down
                break;
            case InputKey::LEFT: if (cursorCol > 0) cursorCol--; // Move cursor left
                break;
            case InputKey::RIGHT: if (cursorCol < BOARD_SIZE - 1) cursorCol++; // Move cursor right
                break;
            case InputKey::LEFT_BRACKET: // '[' key
                if (moveHistoryScroll > 0) moveHistoryScroll--; // Scroll up
                break;
            case InputKey::RIGHT_BRACKET: // ']' key
                if (moveHistoryScroll + 1 < moveHistory.size() - 4) moveHistoryScroll++; // Scroll down
                break;
            case InputKey::ENTER: {
               
                if (board.placeMove(cursorRow, cursorCol, currentPlayer->getType())) {
                    if (board.checkWin(cursorRow, cursorCol, currentPlayer->getType())) {
                        render();
                        displayWinner();
                        isRunning = false;
                    } else {
                        switchTurn();
                    }
                } 
                break;
            }
            case InputKey::ESC:
                isRunning = false; // Exit the game
                break;
            default:
                break;
        }
    } else {
        // Use WASD keys for Player O
        switch (key) {
            case InputKey::UP: if (cursorRow > 0) cursorRow--; // Move cursor up
                break;
            case InputKey::DOWN: if (cursorRow < BOARD_SIZE - 1) cursorRow++; // Move cursor down
                break;
            case InputKey::LEFT: if (cursorCol > 0) cursorCol--; // Move cursor left
                break;
            case InputKey::RIGHT: if (cursorCol < BOARD_SIZE - 1) cursorCol++; // Move cursor right
                break;
            case InputKey::LEFT_BRACKET: // '[' key
                if (moveHistoryScroll > 0) moveHistoryScroll--; // Scroll up
                break;
            case InputKey::RIGHT_BRACKET: // ']' key
                if (moveHistoryScroll + 1 < moveHistory.size() - 4) moveHistoryScroll++; // Scroll down
                break;
            case InputKey::ENTER: {
                if (board.placeMove(cursorRow, cursorCol, currentPlayer->getType())) {
                    if (board.checkWin(cursorRow, cursorCol, currentPlayer->getType())) {
                        render();
                        displayWinner();
                        isRunning = false;
                    } else {
                        switchTurn();   
                    }
                }
                break;
            }
            case InputKey::ESC:
                isRunning = false; // Exit the game
                break;
            default:
                break;
        }
    }

 
    if (board.placeMove(cursorRow, cursorCol, currentPlayer->getType())) {
        moveHistory.push_back({ cursorRow, cursorCol, currentPlayer->getType() });

        if (board.checkWin(cursorRow, cursorCol, currentPlayer->getType())) {
            render();
            displayWinner();
            isRunning = false;
        } else {
            switchTurn();
        }
    }

}

void Game::switchTurn() {
    auto now = chrono::steady_clock::now();
    int elapsed = chrono::duration_cast<chrono::seconds>(now - startTime).count();

    if (currentPlayer->getType() == CellState::PLAYER_X) timeX += elapsed;
    else timeO += elapsed;

    currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
    startTime = chrono::steady_clock::now(); // Restart timer for next player
}

void Game::displayWinner() {
    gotoXY(0, 2 * BOARD_SIZE + 4);
    setTextColor(static_cast<int>(currentPlayer->getType()));
    cout << (currentPlayer->getType() == CellState::PLAYER_X ? "X" : "O") << " wins!" << endl;
    setTextColor(7);
    // Increment the winner's score

    if (currentPlayer->getType() == CellState::PLAYER_X) {
        playerX.incrementScore();
    } else {
        playerO.incrementScore(); 
    }
}

// void Game::moveHistory(vector<string>& history) const {

    
//     string move = format("{}. Player{} ({}, {})", history.size() + 1,
//                      currentPlayer->getType() == CellState::PLAYER_X ? "X" : "O",
//                      row + 1, col + 1);
//     history.push_back(move);
// }


void Game::resetGame() {
    board.reset();
    currentPlayer = &playerX;
    isRunning = true;
}
