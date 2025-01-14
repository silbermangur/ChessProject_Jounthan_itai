#include "Queen.h"

Queen::Queen(char name, char color, std::string position) : Piece(name, color, position)
{
}

bool Queen::move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    if (row != destRow)
    {
        if (col == destCol || (row - destRow == (col - destCol) || (col - destCol) * -1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (col != destCol)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queen::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    int i = 0;
    int j = 0;
    int targetNum2 = 0;
    int targetNum1 = 0;

    if (row == destRow)
    {
        if (col < destCol)
        {
            i = col;
            targetNum1 = destCol;
        }
        else if (destCol < col)
        {
            i = destCol;
            targetNum1 = col;
        }
        for (; i < targetNum1; i++)
        {
            if (board[row][i]->getColor() != '#')
            {
                return true;
            }
        }
        return false;
    }
               
    else
    {
        if (col == destCol)
        {
            if (row < destRow)
            {
                i = row;
                targetNum1 = destRow;
            }
            else if (row > destRow)
            {
                i = destRow;
                targetNum1 = row;
            }
            for (; i < targetNum1; i++)
            {
                if (board[i][col]->getColor() != '#')
                {
                    return true;
                }
            }
            return false;
        }
    
        else
        {
            if (row < destRow && col < destCol)
            {
                i = row;
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
                if (board[i][j]->getColor() != '#')
                {
                    return true;
                }
            }
            return false;
        }
    }   
    return false;
}
