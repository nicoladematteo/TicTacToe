#pragma once

#include "GameBoard.h"

class AiPlayer
{
public:
    GameBoard *board;
    void AiMoveRandom(int *, int);
};