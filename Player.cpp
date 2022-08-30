#include <iostream>
#include <string>
#include "Player.h"
#include "GameBoard.h"

void Player::move(GameBoard *table , int player)
{
    std::string moveString;
    int move = 0;
    bool isInvalid = 0;
    do
    {
        std::cout << "player " << player << " has to move: ";
        getline(std::cin, moveString);
        move = moveString[0] - '1';
        if (move > 8 || move < 0 || table->board[move] != 0)
        {
            std::cout << "Invalid input" << std::endl;
            isInvalid = true;
        }
        else
        {
            table->board[move] = player;
            isInvalid = false;
            std::cout << std::endl;
        }
    } while (isInvalid);
}