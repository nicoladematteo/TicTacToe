#include <iostream>
#include <string>

#include "TTTreprise.h"

int main()
{
    int actualBoard[9] = {0};
    GameBoard table;
    Player playerOne, playerTwo;

    table.instruction();

    while (true)
    {
        playerOne.playerMove(actualBoard, 1);
        table.outputBoard(actualBoard);

        if (table.isGameOver(actualBoard))
            break;
        playerTwo.playerMove(actualBoard, 2);
        table.outputBoard(actualBoard);

        if (table.isGameOver(actualBoard))
            break;
    }
}