#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Player.h"

int main()
{

    GameBoard table;
    Player playerOne, playerTwo;

    table.instruction();

    while (true)
    {
        playerOne.playerMove(table.board, 1);
        table.outputBoard();

        if (table.isGameOver())
            break;
        playerTwo.playerMove(table.board, 2);
        table.outputBoard();

        if (table.isGameOver())
            break;
    }
}