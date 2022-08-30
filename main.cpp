#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Player.h"
#include "AiPlayer.h"
#include "IPlayer.h"

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
            playerOne.move(&table, 1);
            table.outputBoard();

            if (table.isGameOver())
                break;
            aiPlayer.move(&table, 2);

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
                playerOne.move(&table, 1);
                table.outputBoard();

                if (table.isGameOver())
                    break;
                playerTwo.move(&table, 2);
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
            aiPlayer.move(&table, 1);
            table.outputBoard();

            if (table.isGameOver())
                break;
            aiPlayer.move(&table, 2);
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