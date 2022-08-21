#pragma once

#include "GameBoard.h"

class Player
{
public:
    GameBoard *board;
    void playerMove(int *, int);
};