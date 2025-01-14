#include "Queen.h"

bool Queen::mov(int srcRow, int srcCol, int dstRow, int dstCol, Piece* (&board)[8][8])
{
    if (srcRow == dstRow || srcCol == dstCol ||
        abs(dstRow - srcRow) == abs(dstCol - srcCol)) 
    {  
        return true;
    }
    return false;
}

bool Queen::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    Rock rock(' ', ' ', " ");
    Bishop bishop(' ', ' ', " ");

    // Rook's movement check: straight line
    if (row == destRow || col == destCol) 
    {
        return rock.isPieceInWay(board, row, col, destRow, destCol);  // Delegate to Rock
    }
    // Bishop's movement check: diagonal
    if (abs(destRow - row) == abs(destCol - col)) 
    {
        return bishop.isPieceInWay(board, row, col, destRow, destCol);  // Delegate to Bishop
    }
    return false;
}
