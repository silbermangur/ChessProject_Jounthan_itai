#include "Bishop.h"

Bishop::Bishop(char name, char color) : Piece(name, color)
{
}

bool Bishop::move(Piece* (&board)[8][8], int command[])
{
    if (command[1] - command[3] == (command[0] - command[2]) || (command[0] - command[2]) * -1)
    {
        return isPieceInWay;
    }
    else
    {
        return false;
    }
}

bool Bishop::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    int i, j, targetNum1, targetNum2 = 0;

    if (row < destRow && col < destCol)
    {
        i = row - 1;
        targetNum1 = destRow - 1;
        j = col - 1;
        targetNum2 = destCol - 1;
    }
    else if (row < destRow && destCol < col)
    {
        i = row - 1;
        targetNum1 = destRow - 1;
        j = destCol - 1;
        targetNum2 = col - 1;
    }
    else if (destRow < row && col < destCol)
    {
        i = destRow - 1;
        targetNum1 = row - 1;
        j = col - 1;
        targetNum2 = destCol - 1;
    }
    else if (row < destRow && destCol < col)
    {
        i = destRow - 1;
        targetNum1 = row - 1;
        j = destCol - 1;
        targetNum2 = col - 1;
    }

    for (; i < targetNum1 && j < targetNum2; i++, j++)
    {
        if (board[i][j]->getColor() != '#')
        {
            return false;
        }
    }
    return true;
}
