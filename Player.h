#pragma once

#include "IPlayer.h"
#include "GameBoard.h"

class Player : public IPlayer
{
public:
    // ~Player();
    void move(GameBoard *, int);
};