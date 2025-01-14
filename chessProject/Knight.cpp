#include "Knight.h"

bool Knight::mov(int srcRow, int srcCol, int dstRow, int dstCol, Piece* (&board)[8][8])
{
	if (dstRow == (srcRow + 1 ) && dstCol == (srcCol + 2) ||
		dstRow == (srcRow + 1) && dstCol == (srcCol - 2) ||
		dstRow == (srcRow - 1) && dstCol == (srcCol + 2) ||
		dstRow == (srcRow - 1) && dstCol == (srcCol - 2) ||
		dstRow == (srcRow + 2) && dstCol == (srcCol + 1) ||
		dstRow == (srcRow + 2) && dstCol == (srcCol - 1) ||
		dstRow == (srcRow - 2) && dstCol == (srcCol + 1) ||
		dstRow == (srcRow - 2) && dstCol == (srcCol - 1))
	{
		return true;
	}
	return false;
}

bool Knight::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
	return false;
}
