#pragma once

#include "player.h"

struct MoveRecord {
    int row;
    int col;
    CellState player;
};