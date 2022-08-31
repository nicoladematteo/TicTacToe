#pragma once

#include "IPlayer.h"
#include "GameBoard.h"

class Player : public IPlayer
{
public:
    void move(GameBoard *, int);
};