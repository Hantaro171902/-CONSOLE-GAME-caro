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
    char ch1 = getchar();

    if (ch1 == "\033") { // Escape sequence
        char ch2 = getchar();
        char ch3 = getchar();
        if (ch2 == "[") {
            switch (ch3) {
                case 'A': // Arrow Up
                    key = InputKey::UP;
                    break;
                case 'B': // Arrow Down
                    key = InputKey::DOWN;
                    break;
                case 'C': // Arrow Right
                    key = InputKey::RIGHT;
                    break;
                case 'D': // Arrow Left
                    key = InputKey::LEFT;
                    break;
                default:
                    key = InputKey::NONE;
                    break;
            }
        } else if (ch1 == "\n" || ch1 == '\r') { // Enter key
            key = InputKey::ENTER;
        } else if (ch1 == 27) { // Escape key
            key = InputKey::ESC;
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old terminal settings
    return key;
}