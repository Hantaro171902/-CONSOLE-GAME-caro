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

void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}


