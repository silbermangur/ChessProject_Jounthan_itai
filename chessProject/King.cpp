#include "King.h"

bool King::mov(int srcRow, int srcCol, int dstRow, int dstCol, Piece* (&board)[8][8])
{
    
    if (dstRow == (srcRow + 1)  && dstCol == (srcCol + 1)||
        dstRow == (srcRow + 1) && dstCol == (srcCol - 1)||
        dstRow == (srcRow + 1) && dstCol == srcCol ||
        dstRow == (srcRow - 1) && dstCol == (srcCol - 1) ||
        dstRow == (srcRow - 1) && dstCol == (srcCol + 1) ||
        dstRow == (srcRow - 1) && dstCol == srcCol ||
        dstRow == srcRow && dstCol == (srcCol +1) || 
        dstRow == srcRow && dstCol == (srcCol - 1))
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
