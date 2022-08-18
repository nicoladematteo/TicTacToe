#pragma once

class GameBoard
{
private:
    int board[9] = {0};

    char numberToLetter(int);

    bool compareSpots(int, int, int);

    int getWinner(int *);

public:
    void instruction();

    void outputBoard(int *);

    bool isGameOver(int *);
};