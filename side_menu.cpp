#include <iostream>
#include <iomanip>
#include "ultils.h"
#include "side_menu.h"

using namespace std;

void drawSideMenu(int x, int y, int scoreX, int scoreO, int timeX, int timeO) {
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