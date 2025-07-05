#pragma once

void gotoXY(int x, int y);
void clearScreen();
void setTextColor(int color);
void hideCursor();
int getch();    // For key input
bool kbhit();   // For non-blocking keyboard input

