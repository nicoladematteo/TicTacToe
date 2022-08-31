#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Player.h"
#include "AiPlayer.h"
#include "IPlayer.h"

IPlayer *CreatePlayer(bool human)
{
    if (human)
        return new Player();
    else
        return new AiPlayer();
}

int main()
{

    GameBoard table;
    Player playerOne, playerTwo;
    AiPlayer aiPlayer;

    IPlayer *player1 = new Player;
    IPlayer *player2 = new Player;

    char oper;
    std::cout << "press a to play 1vs1, b to play 1vsAi or c AiVsAi" << std::endl;
    std::cin >> oper;

    switch (oper)
    {
    case 'a':
    {
        player1 = CreatePlayer(true);
        player2 = CreatePlayer(true);
    }
    break;
    case 'b':
    {
        player1 = CreatePlayer(true);
        player2 = CreatePlayer(false);
    }
    break;
    case 'c':
    {
        player1 = CreatePlayer(false);
        player2 = CreatePlayer(false);
    }
    break;
    }

    table.instruction();
    while (true)
    {
        player1->move(&table, 1);
        table.outputBoard();

        if (table.isGameOver())
            break;

        player2->move(&table, 2);
        table.outputBoard();

        if (table.isGameOver())
            break;
    }
}