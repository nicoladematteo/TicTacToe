#include <iostream>
#include <string>
#include "AiPlayer.h"
#include "GameBoard.h"

void AiPlayer::AiMoveRandom(int *board, int player)
{
    srand(time(0));
    int move = 0;
    do
    {
        move = rand() % 9;
    } while (board[move] != 0);

    board[move] = player;
}