#pragma once
#include <iostream>
#include "ultils.h"

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

class Menu {
private:

    // Add any private members if needed
public:
    void drawMainMenu();
    // void drawSettingsMenu();
    // void drawAboutMenu();
    // void drawExitMenu();
    void drawInstructions(int x, int y);
    void drawSideMenu(int x, int y, int scoreX, int scoreO, int timeX, int timeO);
};


// void drawSettingsMenu();
// void drawAboutMenu();
// void drawExitMenu();
