#include <iostream>
#include "menu.h"
#include "ultils.h"

using namespace std;

void drawMainMenu() {
    const int MENU_WIDTH = 40;
    const int MENU_HEIGHT = 8;
    const x = 20;
    const y = 5;

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