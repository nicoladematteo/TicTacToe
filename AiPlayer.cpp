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

void AiPlayer::move(GameBoard *table, int player)
{
    int otherPlayer = (player % 2) + 1; // inverse 1 with 2 and viceversa
    int opponentIsGoingToWin = table->winInTheNextMove(otherPlayer);
    int playerIsGoingToWin = table->winInTheNextMove(player);
    if (playerIsGoingToWin != -1)
    {
        table->board[playerIsGoingToWin] = player;
    }
    else if (opponentIsGoingToWin != -1)
    {
        table->board[opponentIsGoingToWin] = player;
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