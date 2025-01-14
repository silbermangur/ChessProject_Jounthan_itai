#include "Bishop.h"

bool Bishop::mov(int srcRow, int srcCol, int dstRow, int dstCol, Piece* (&board)[8][8])
{
    if (abs((dstRow - srcRow)) == abs((dstCol - srcCol)))
    {
        return true;
    }
    return false;
}

bool Bishop::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    int colum = col;
    if (destRow > row)
    {
        if (destCol > col)
        {
            for (int i = row + 1; i < destRow; i++)
            {
                colum++;
                if (board[i][colum]->getName() != '#')
                {
                    return true;
                }
            }
        }
        else if (destCol < col)
        {
            for (int i = row + 1; i < destRow; i++)
            {
                colum--;
                if (board[i][colum]->getName() != '#')
                {
                    return true;
                }
            }
        }
        
    }
    else if (destRow < row)
    {
        if (destCol > col)
        {
            for(int i = row - 1; i > destRow; i--)
            {
                colum++;
                if (board[i][colum]->getName() != '#')
                {
                    return true;
                }
            }
        }
        else if (destCol < col)
        {
            for(int i = row - 1; i > destRow; i--)
            {
                colum--;
                if (board[i][colum]->getName() != '#')
                {
                    return true;
                }
            }
        }
    }

    return false;
}
