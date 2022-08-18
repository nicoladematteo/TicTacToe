#include <iostream>
#include <string>
#include "GameBoard.h"

void GameBoard::instruction()
{
    std::cout << "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n\n";
}

char GameBoard::numberToLetter(int x)
{
    ((x > 0) ? (x == 1) ? 'X' : 'O' : ' ');
    if (x > 0)
    {
        if (x == 1)
            return 'X';
        if (x == 2)
            return 'O';
    }
    else
        return ' ';
}

void GameBoard::outputBoard(int board[9])
{
    for (int line = 0; line < 3; line++)
    {
        for (int spot = 0; spot < 3; spot++)
        {
            std::cout << numberToLetter(board[3 * line + spot]) << ((spot < 2) ? '|' : '\n');
        }
        std::cout << ((line < 2) ? "-----\n" : "\n");
    }
}

bool GameBoard::compareSpots(int spot1, int spot2, int spot3)
{
    if ((spot1 == spot2) && (spot2 == spot3) && spot1 != 0)
        return true;
    else
        return false;
}

int GameBoard::getWinner(int board[9])
{
    int winner = 0;
    for (int x = 0; x < 3; x++)
    {
        if (compareSpots(board[3 * x], board[(3 * x) + 1], board[(3 * x) + 2]))
        {
            winner = board[3 * x];
            break;
        }
        else if (compareSpots(board[x], board[x + 3], board[x + 6]))
        {
            winner = board[x];
            break;
        }
        else if (compareSpots(board[2 * x], board[4], board[8 - (2 * x)]) && (x < 2))
        {
            winner = board[4];
            break;
        }
    }
    return winner;
}

bool GameBoard::isGameOver(int board[9])
{
    int winner = getWinner(board);
    if (winner > 0)
    {
        std::cout << numberToLetter(winner) << " wins!" << std::endl;
        return true;
    }
    for (int x = 0; x < 9; x++)
    {
        if (board[x] == 0)
            return false;
    }
    std::cout << "Tie!\n\n";
    return true;
}