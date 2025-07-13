#pragma once
#include <iostream>
#include "ultils.h"
#include "player.h"
#include <vector>


// ╔═════════════════════════════════╗
// ║          CARO GAME MENU         ║
// ╠═════════════════════════════════╣
// ║ 1. Start Game                   ║
// ║ 2. Load Game                    ║
// ║ 3. Settings                     ║
// ║ 4. Exit                         ║
// ╚═════════════════════════════════╝
// // WINNER ROW

using namespace std;

struct MoveRecord {
    int row; // Row of the move
    int col; // Column of the move
    CellState player; // Player who made the move
};

class Menu {
private:
    vector<MoveRecord> moveHistory; // History of moves made in the game

    // Add any private members if needed
public:
    void drawMainMenu();
    void drawLogo(int x, int y);
    void drawMoveHistory(int x, int y, const vector<string>& history);
    // void drawSettingsMenu();
    // void drawAboutMenu();
    // void drawExitMenu();
    void drawInstructions(int x, int y);
    void drawSideMenu(int x, int y, int scoreX, int scoreO, int timeX, int timeO);
};


// void drawSettingsMenu();
// void drawAboutMenu();
// void drawExitMenu();
