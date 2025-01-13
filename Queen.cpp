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
    int i, j, targetNum1, targetNum2 = 0;

    if (row == destRow)
    {
        if (col < destCol)
        {
            i = col - 1;
            targetNum1 = destCol - 1;
        }
        else if (destCol < col)
        {
            i = destCol - 1;
            targetNum1 = col - 1;
        }
        for (; i < targetNum1; i++)
        {
            if (board[row - 1][i]->getColor() != '#')
            {
                return false;
            }
        }
        return true;
    }
               
    else
    {
        if (col == destCol)
        {
            if (row < destRow)
            {
                i = row - 1;
                targetNum1 = destRow - 1;
            }
            else if (row > destRow)
            {
                i = destRow - 1;
                targetNum1 = row - 1;
            }
            for (; i < targetNum1; i++)
            {
                if (board[i][col - 1]->getColor() != '#')
                {
                    return false;
                }
            }
            return true;
        }
    
        else
        {
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
    }   
    return false;
}
