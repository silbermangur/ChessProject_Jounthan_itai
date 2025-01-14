#include "Bishop.h"

Bishop::Bishop(char name, char color, std::string position) : Piece(name, color, position)
{
}

bool Bishop::move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    if (row - destRow == (col - destCol) || (col - destCol) * -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Bishop::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    int i = 0;
    int j = 0;
    int targetNum2 = 0;
    int targetNum1 = 0;


    if (row < destRow && col < destCol)
    {
        i = row ;
        targetNum1 = destRow;
        j = col;
        targetNum2 = destCol;
    }
    else if (row < destRow && destCol < col)
    {
        i = row;
        targetNum1 = destRow;
        j = destCol;
        targetNum2 = col;
    }
    else if (destRow < row && col < destCol)
    {
        i = destRow;
        targetNum1 = row;
        j = col;
        targetNum2 = destCol;
    }
    else if (row < destRow && destCol < col)
    {
        i = destRow;
        targetNum1 = row;
        j = destCol;
        targetNum2 = col;
    }

    for (; i <= targetNum1 && j <= targetNum2; i++, j++)
    {
        if (board[i][j]->getName() != '#')
        {
            return true;
        }
    }
    return false;
}
