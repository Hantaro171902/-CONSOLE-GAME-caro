#include "game_logic.h"
#include "animation_loading.h"
#include <iostream>

int main() {
    animLoading();
    Game game;
    game.init();
    game.run();
    return 0;
}
