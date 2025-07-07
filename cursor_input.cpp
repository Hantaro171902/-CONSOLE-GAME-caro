#include "cursor_input.h"
#include "ultils.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>     // for read()

using namespace std;

InputKey getInputKey() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    InputKey key = InputKey::NONE;
    char ch = getchar();

    if (read(STDIN_FILENO, &ch, 1) == 1) { // Arrow key escape sequence
        if (ch == '\033') {
            char seq[2];
            if (read(STDIN_FILENO, &seq[0], 1) == 1 && 
                read(STDIN_FILENO, &seq[1], 1) == 1) {
                switch (seq[1]) {
                    case 'A': return InputKey::UP;
                    case 'B': return InputKey::DOWN;
                    case 'C': return InputKey::RIGHT;
                    case 'D': return InputKey::LEFT;
                }
            }
        } else {
            switch (ch) {
                case 'w': case 'W': return InputKey::UP;
                case 's': case 'S': return InputKey::DOWN;
                case 'a': case 'A': return InputKey::LEFT;
                case 'd': case 'D': return InputKey::RIGHT;
                case '\n': return InputKey::ENTER;
                case 27:   return InputKey::ESC; // Escape
                default:   return InputKey::NONE;
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore original settings
    return InputKey::NONE;
}