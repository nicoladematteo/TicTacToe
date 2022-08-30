#pragma once

#include "IPlayer.h"
#include "GameBoard.h"

class AiPlayer : public IPlayer
{
public:
    // ~AiPlayer();
    void move(GameBoard *, int);

private:
    void aiMoveRandom(int *, int);
};