
#include <iostream>
#include <string>
#include "TTTreprise.h"

int main()
{
    int board[9] = {0};

    std::cout << "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n\n";

    while (true)
    {
        playerMove(board, 1);

        outputBoard(board);
        if (isGameOver(board))
            break;

        playerMove(board, 2);

        outputBoard(board);
        if (isGameOver(board))
            break;
    }
}