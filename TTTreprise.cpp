
#include <iostream>
#include <string>
#include "TTTreprise.h"

int main()
{
    int board[9] = {0};
    int moveX, moveO;
    bool isInvalidX = 0;
    bool isInvalidO = 0;
    std::string moveXString, moveOString;

    std::cout << "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n\n";

    while (true)
    {
        playerMove(moveX, moveXString, board, 1);

        outputBoard(board);
        if (gameOver(board))
            break;

        playerMove(moveO, moveOString, board, 2);

        outputBoard(board);
        if (gameOver(board))
            break;
    }
}