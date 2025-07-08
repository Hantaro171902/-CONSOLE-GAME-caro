// ultils.cpp
#include "ultils.h"
#include <iostream>

using namespace std;

// CONSOLE
#ifdef _WIN32

void gotoXY(int x, int y) {
    static HANDLE h = NULL;
    if (!h) h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(h, c);
}

void clearScreen() {
    system("cls");
}

void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hideCursor() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(h, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(h, &cursorInfo);
}

int getch() {
    return _getch();
}

bool kbhit() {
    return _kbhit();
}

#else

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1); // ANSI escape code for cursor
}


void clearScreen() {
    cout << "\033[2J\033[1;1H";  // Clear screen + move to top-left
    cout << "\033[?25l";         // Hide cursor
}

void clearTerminal() {
    // Full terminal reset (clears everything, cursor, formatting, etc.)
    cout << "\033c";
    cout << "\033[?25l"; // Hide cursor
}

// Box drawing characters
const char SYMBOL_HORIZONTAL[]   = "\u2500"; // ─
const char SYMBOL_VERTICAL[]     = "\u2502"; // │
const char SYMBOL_TOP_LEFT[]     = "\u250C"; // ┌
const char SYMBOL_TOP_RIGHT[]    = "\u2510"; // ┐
const char SYMBOL_BOTTOM_LEFT[]  = "\u2514"; // └
const char SYMBOL_BOTTOM_RIGHT[] = "\u2518"; // ┘
const char SYMBOL_T_LEFT[]       = "\u251C"; // ├
const char SYMBOL_T_RIGHT[]      = "\u2524"; // ┤
const char SYMBOL_T_TOP[]        = "\u252C"; // ┬
const char SYMBOL_T_BOTTOM[]     = "\u2534"; // ┴
const char SYMBOL_INTERSECT[]    = "\u253C"; // ┼


// Double line box drawing characters
const char SYMBOL_DOUBLE_HORIZONTAL[]   = "\u2550"; // ═
const char SYMBOL_DOUBLE_VERTICAL[]     = "\u2551"; // ║
const char SYMBOL_DOUBLE_TOP_LEFT[]     = "\u2554"; // ╔
const char SYMBOL_DOUBLE_TOP_RIGHT[]    = "\u2557"; // ╗
const char SYMBOL_DOUBLE_BOTTOM_LEFT[]  = "\u255A"; // ╚    
const char SYMBOL_DOUBLE_BOTTOM_RIGHT[] = "\u255D"; // ╝
const char SYMBOL_DOUBLE_T_LEFT[]       = "\u2560"; // ╠
const char SYMBOL_DOUBLE_T_RIGHT[]      = "\u2563"; // ╣
const char SYMBOL_DOUBLE_T_TOP[]        = "\u2566"; // ╦
const char SYMBOL_DOUBLE_T_BOTTOM[]     = "\u2569"; // ╩
const char SYMBOL_DOUBLE_INTERSECT[]    = "\u256C"; // ╬

const char BLOCK_FULL[]   = "\u2588"; // █
const char BLOCK_HALF[]   = "\u2592"; // ▒

void setTextColor(int color) {
    // ANSI escape codes for text colors
    switch (color) {
        case 30: cout << "\033[30m"; break; // Black
        case 31: cout << "\033[31m"; break; // Red
        case 32: cout << "\033[32m"; break; // Green
        case 33: cout << "\033[33m"; break; // Yellow
        case 34: cout << "\033[34m"; break; // Blue
        case 35: cout << "\033[35m"; break; // Magenta
        case 36: cout << "\033[36m"; break; // Cyan
        case 37: cout << "\033[37m"; break; // White
        default: cout << "\033[0m"; break; // Reset to default
    }
}

void hideCursor() {
    cout << "\033[?25l"; // Hide cursor
}

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

bool kbhit() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    if(ch != EOF) {
        ungetc(ch, stdin); // Put the character back into the input buffer
        return true;
    }
    
    return false;
}

#endif
