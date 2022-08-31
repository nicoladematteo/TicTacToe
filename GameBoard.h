#pragma once

class GameBoard
{

private:
    char numberToLetter(int);
    bool compareSpots(int, int, int);
    int getWinner(int *);
    int temporary[9] = {0};

public:
    int board[9] = {0};
    void instruction();
    void outputBoard();
    bool isGameOver();
    int winInTheNextMove(int);
};