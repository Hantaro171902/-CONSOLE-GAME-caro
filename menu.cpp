#include <iostream>
#include "menu.h"
#include "ultils.h"
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void Menu::drawMainMenu() {
    const int MENU_WIDTH = 40;
    const int MENU_HEIGHT = 8;
    const int x = 20;
    const int y = 5;

    clearScreen();
    setTextColor(14); // Yellow for menu title

    // Top border
    gotoXY(x, y);
    cout << SYMBOL_DOUBLE_TOP_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_TOP_RIGHT;

    // Title row
    gotoXY(x, y + 1);
    cout << SYMBOL_DOUBLE_VERTICAL;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << " ";
    cout << SYMBOL_DOUBLE_VERTICAL;

    gotoXY(x + (MENU_WIDTH - 15) / 2, y + 1);  // Center "CARO GAME MENU"
    cout << "CARO GAME MENU";

    // Divider
    gotoXY(x, y + 2);
    cout << SYMBOL_DOUBLE_T_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_T_RIGHT;

    // Menu items
    for (int i = 0; i < 4; ++i) {
        gotoXY(x, y + 3 + i);
        cout << SYMBOL_DOUBLE_VERTICAL << "  ";

        switch (i) {
            case 0: cout << "1. Start Game"; break;
            case 1: cout << "2. Load Game"; break;
            case 2: cout << "3. Settings"; break;
            case 3: cout << "4. Exit"; break;
        }

        // Fill space to the end of menu line
        int contentLength = 16;  // Length of menu item text
        for (int j = 0; j < MENU_WIDTH - contentLength - 2; ++j) cout << " ";

        cout << SYMBOL_DOUBLE_VERTICAL;
    }

    // Bottom border
    gotoXY(x, y + MENU_HEIGHT);
    cout << SYMBOL_DOUBLE_BOTTOM_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_BOTTOM_RIGHT;

    setTextColor(7); // Reset to default
}


// Draw side menu
// ╔═══════╦══════════╦══════════╦═══════╗
// ║ 00:00 ║ Player O ║ Player X ║ 00:00 ║
// ╠═══════╩══════════╬══════════╩═══════╣
// ║     Score: 0     ║     Score: 0     ║
// ╚══════════════════╩══════════════════╝

void Menu::drawSideMenu(int x, int y, int scoreX, int scoreO, int timeX, int timeO) {
    const int MENU_WIDTH = 35;
    const int MENU_HEIGHT = 6;

    string title = "CARO GAME SCORE";
    ostringstream rowO, rowX;
    rowO << " Player O: " << setw(2) << scoreO << " | Time: " << setw(2) << timeO << "s ";
    rowX << " Player X: " << setw(2) << scoreX << " | Time: " << setw(2) << timeX << "s ";

    // Top border
    gotoXY(x, y);
    cout << SYMBOL_DOUBLE_TOP_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_TOP_RIGHT;

    // Draw the title row
    gotoXY(x, y + 1);
    cout << SYMBOL_DOUBLE_VERTICAL;
    cout << title;
    for (int i = 0; i < MENU_WIDTH - title.length(); ++i) cout << " ";
    cout << SYMBOL_DOUBLE_VERTICAL;

    // Draw the divider
    gotoXY(x, y + 2);
    cout << SYMBOL_DOUBLE_T_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_T_RIGHT;

    // Draw O
    gotoXY(x, y + 3);
    cout << SYMBOL_DOUBLE_VERTICAL << rowO.str();
    for (int i = 0; i < MENU_WIDTH - rowO.str().length(); ++i) cout << " ";
    cout << SYMBOL_DOUBLE_VERTICAL;

    // Draw X
    gotoXY(x, y + 4);
    cout << SYMBOL_DOUBLE_VERTICAL << rowX.str();
    for (int i = 0; i < MENU_WIDTH - rowX.str().length(); ++i) cout << " ";
    cout << SYMBOL_DOUBLE_VERTICAL;

    // Draw the bottom border
    gotoXY(x, y + 5);
    cout << SYMBOL_DOUBLE_BOTTOM_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_BOTTOM_RIGHT;
}

// Draw instructions box
// ╔═════════════════════════════════╗
// ║          INSTRUCTIONS           ║
// ╠═════════════════════════════════╣
// ║ ↑ ↓ ← →  : Move cursor          ║
// ║ ENTER    : Place move           ║
// ║ ESC      : Exit game            ║
// ║ Q        : Quit to menu         ║
// ║ R        : Restart game         ║
// ╚═════════════════════════════════╝

void Menu::drawInstructions(int x, int y) {
    const int BOX_WIDTH = 30;

    const vector<string> instructions = {
        "↑ ↓ ← →  : Move cursor",
        "ENTER    : Place move",
        "ESC      : Exit game",
        "Q        : Quit to menu",
        "R        : Restart game"
    };

    int height = instructions.size() + 3; // 3 for top, title, bottom

    // Top border
    gotoXY(x, y);
    cout << SYMBOL_DOUBLE_TOP_LEFT;
    for (int i = 0; i < BOX_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_TOP_RIGHT;

    // Title
    gotoXY(x, y + 1);
    cout << SYMBOL_DOUBLE_VERTICAL;
    setTextColor(36); // Cyan
    cout << " INSTRUCTIONS ";
    setTextColor(7);
    for (int i = 0; i < BOX_WIDTH - 15; ++i) cout << " ";
    cout << SYMBOL_DOUBLE_VERTICAL;

    // Instructions
    for (int i = 0; i < instructions.size(); ++i) {
        gotoXY(x, y + 2 + i);
        cout << SYMBOL_DOUBLE_VERTICAL << " ";

        setTextColor(33); // Yellow for key part
        string line = instructions[i];
        size_t colon = line.find(':');
        if (colon != string::npos) {
            cout << left << setw(13) << line.substr(0, colon);
            setTextColor(7); // Reset for instruction text
            cout << " : " << line.substr(colon + 2);
        } else {
            cout << setw(BOX_WIDTH - 2) << line;
        }

        // Padding and right border
        int contentLength = line.length();
        int padding = BOX_WIDTH - 2 - contentLength;
        for (int s = 0; s < padding; ++s) cout << " ";
        cout << SYMBOL_DOUBLE_VERTICAL;
    }

    // Bottom border
    gotoXY(x, y + height - 1);
    cout << SYMBOL_DOUBLE_BOTTOM_LEFT;
    for (int i = 0; i < BOX_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_BOTTOM_RIGHT;

    setTextColor(7); // Reset color
}