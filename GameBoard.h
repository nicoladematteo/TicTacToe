#pragma once

class GameBoard
{

private:
    char numberToLetter(int);
    bool compareSpots(int, int, int);
    int getWinner();

public:
    int board[9] = {0};
    void instruction();
    void outputBoard();
    bool isGameOver();
};