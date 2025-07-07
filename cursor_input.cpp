#include "cursor_input.h"
#include "ultils.h"
#include <iostream>
#include <termios.h>

using namespace std;

InputKey getInputKey() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    InputKey key = InputKey::NONE;
    char ch = getch();git add 


    if (kbhit()) {
        int ch = getch();
        if (ch == 27) { // Escape key
            return InputKey::ESC;
        } else if (ch == 10 || ch == 13) { // Enter key
            return InputKey::ENTER;
        } else if (ch == 65) { // Arrow Up
            return InputKey::UP;
        } else if (ch == 66) { // Arrow Down
            return InputKey::DOWN;
        } else if (ch == 68) { // Arrow Left
            return InputKey::LEFT;
        } else if (ch == 67) { // Arrow Right
            return InputKey::RIGHT;
        }
    }
    return InputKey::NONE;
}