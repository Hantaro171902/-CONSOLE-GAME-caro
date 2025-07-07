#include <iostream>
#include <iomanip>
#include "ultils.h"
#include "side_menu.h"

using namespace std;

void drawSideMenu(int x, int y, int scoreX, int scoreO, int timeX, int timeO) {
    const int MENU_WIDTH = 30;
    const int MENU_HEIGHT = 8;

    // Draw the side menu box
    gotoXY(x, y);
    cout << SYMBOL_DOUBLE_TOP_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_TOP_RIGHT;

    // Draw the title row
    gotoXY(x, y + 1);
    cout << SYMBOL_DOUBLE_VERTICAL << " SIDE MENU ";
    for (int i = 0; i < MENU_WIDTH - 12; ++i) cout << " ";
    cout << SYMBOL_DOUBLE_VERTICAL;

    // Draw the divider
    gotoXY(x, y + 2);
    cout << SYMBOL_DOUBLE_T_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_T_RIGHT;

    // Draw the score and time rows
    gotoXY(x, y + 3);
    cout << SYMBOL_DOUBLE_VERTICAL << " Player O: " << setw(2) << scoreO 
         << " | Time: " << setw(2) << timeO << "s ";
    for (int i = 0; i < MENU_WIDTH - 28; ++i) cout << " ";
    cout << SYMBOL_DOUBLE_VERTICAL;

    gotoXY(x, y + 4);
    cout << SYMBOL_DOUBLE_VERTICAL << " Player X: " << setw(2) << scoreX 
         << " | Time: " << setw(2) << timeX << "s ";
    for (int i = 0; i < MENU_WIDTH - 28; ++i) cout << " ";
    cout << SYMBOL_DOUBLE_VERTICAL;

    // Draw the bottom border
    gotoXY(x, y + MENU_HEIGHT - 1);
    cout << SYMBOL_DOUBLE_BOTTOM_LEFT;
    for (int i = 0; i < MENU_WIDTH; ++i) cout << SYMBOL_DOUBLE_HORIZONTAL;
    cout << SYMBOL_DOUBLE_BOTTOM_RIGHT;
}