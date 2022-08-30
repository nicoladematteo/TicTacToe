#include <iostream>
#include <string>
#include "AiPlayer.h"
#include "GameBoard.h"

void AiPlayer::aiMoveRandom(int *board, int player)
{
    srand(time(0));
    int move = 0;
    do
    {
        move = rand() % 9;
    } while (board[move] != 0);

    board[move] = player;
}

void AiPlayer::move(GameBoard *table, int player) //try to put & instead *
{
    int otherPlayer = (player %2) +1; //inverse 1 with 2 and viceversa
    if (table->winInTheNextMove(otherPlayer) != -1)
    {
        table->board[table->winInTheNextMove(otherPlayer)] = player;
    }
    else if (table->winInTheNextMove(player) != -1)
    {
        table->board[table->winInTheNextMove(player)] = player;
    }
    else if (table->board[4] == 0)
    {
        table->board[4] = player;
    }
    else
    {
        aiMoveRandom(table->board, player);
    }
}