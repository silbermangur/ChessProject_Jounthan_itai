#include "King.h"

bool King::move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    
    if (destRow == (row + 1)  && destCol == (col + 1)||
        destRow == (row + 1) && destCol == (col - 1)||
        destRow == (row + 1) && destCol == col ||
        destRow == (row - 1) && destCol == (col - 1) ||
        destRow == (row - 1) && destCol == (col + 1) ||
        destRow == (row - 1) && destCol == col ||
        destRow == row && destCol == (col +1) || 
        destRow == row && destCol == (col - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool King::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
	return false;
}
