#pragma once

void gotoXY(int x, int y);
void clearScreen();
void setTextColor(int color);
void hideCursor();
int getch();    // For key input
bool kbhit();   // For non-blocking keyboard input

// Box drawing characters (UTF-8)
extern const char SYMBOL_HORIZONTAL[];
extern const char SYMBOL_VERTICAL[];
extern const char SYMBOL_TOP_LEFT[];
extern const char SYMBOL_TOP_RIGHT[];
extern const char SYMBOL_BOTTOM_LEFT[];
extern const char SYMBOL_BOTTOM_RIGHT[];
extern const char SYMBOL_T_LEFT[];
extern const char SYMBOL_T_RIGHT[];
extern const char SYMBOL_T_TOP[];
extern const char SYMBOL_T_BOTTOM[];
extern const char SYMBOL_INTERSECT[];

// Double line box drawing characters (UTF-8)
extern const char SYMBOL_DOUBLE_HORIZONTAL[];
extern const char SYMBOL_DOUBLE_VERTICAL[];
extern const char SYMBOL_DOUBLE_TOP_LEFT[];         
extern const char SYMBOL_DOUBLE_TOP_RIGHT[];
extern const char SYMBOL_DOUBLE_BOTTOM_LEFT[];
extern const char SYMBOL_DOUBLE_BOTTOM_RIGHT[];
extern const char SYMBOL_DOUBLE_T_LEFT[];
extern const char SYMBOL_DOUBLE_T_RIGHT[];
extern const char SYMBOL_DOUBLE_T_TOP[];
extern const char SYMBOL_DOUBLE_T_BOTTOM[];
extern const char SYMBOL_DOUBLE_INTERSECT[];

