#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Player.h"
#include "AiPlayer.h"

int main()
{

    GameBoard table;
    Player playerOne, playerTwo;
    AiPlayer aiPlayer;

    table.instruction();

    char oper;
    char operTwo;
    std::cout << "Do you want to play: \n\n 1VsAI, press a \n\n 1Vs1, press b. " << std::endl;
    std::cin >> oper;

    switch (oper)
    {
    case 'a':
        while (true)
        {
            playerOne.playerMove(table.board, 1);
            table.outputBoard();

            if (table.isGameOver())
                break;

            if (table.winInTheNextMove(1) != -1)
            {
                table.board[table.winInTheNextMove(1)] = 2;
            }
            else if (table.winInTheNextMove(2) != -1)
            {
                table.board[table.winInTheNextMove(2)] = 2;
            }
            else if (table.board[4] == 0)
            {
                table.board[4] = 2;
            }
            else
            {
                aiPlayer.AiMoveRandom(table.board, 2);
            }
            table.outputBoard();

            if (table.isGameOver())
                break;
        }
        break;

    case 'b':
        std::cout << "1 or 2?" << std::endl;
        std::cin >> operTwo;

        switch (operTwo)
        {
        case '1':

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
            break;
        default:
            break;
        }

    case '3':

        while (true)
        {
            aiPlayer.AiMoveRandom(table.board, 1);
            table.outputBoard();

            if (table.isGameOver())
                break;
            aiPlayer.AiMoveRandom(table.board, 2);
            table.outputBoard();

            if (table.isGameOver())
                break;
        }
        break;

    default:
        // operator is doesn't match any case constant (+, -, *, /)
        std::cout << "Error! The operator is not correct";
        break;
    }
}

// you don't wanna loose , who knows what is going to happen, you can not win