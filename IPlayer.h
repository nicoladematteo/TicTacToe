#pragma once

#include "GameBoard.h"

class IPlayer
{
    public:
    virtual void move (GameBoard *, int) = 0;
    // virtual ~IPlayer(){};
};