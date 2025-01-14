#include "Pawn.h"

bool Pawn::mov(int srcRow, int srcCol, int dstRow, int dstCol, Piece* (&board)[8][8])
{
    if (this->getColor() == 'b')
    {
        if (hasMoved)
        {
            if (dstRow == (srcRow + 1) && dstCol == srcCol &&
                board[dstRow][dstCol]->getName() == '#' ||
                dstRow == (srcRow +1) && dstCol == (srcCol + 1) &&
                board[dstRow][dstCol]->getColor() == 'w'||
                dstRow == (srcRow + 1) && dstCol == (srcCol - 1) &&
                board[dstRow][dstCol]->getColor() == 'w')
            {
                return true;
            }
            
        }
        else
        {
            if (dstRow == (srcRow + 2) && dstCol == srcCol &&
                board[dstRow - 1][dstCol]->getName() == '#' &&
                board[dstRow][dstCol]->getName() == '#' ||
                dstRow == (srcRow + 1) && dstCol == srcCol &&
                board[dstRow][dstCol]->getName() == '#' ||
                dstRow == (srcRow + 1) && dstCol == (srcCol + 1) &&
                board[dstRow][dstCol]->getColor() == 'b' ||
                dstRow == (srcRow + 1) && dstCol == (srcCol - 1) &&
                board[dstRow][dstCol]->getColor() == 'b')
            {
                return true;
            }
        }
    }
    else if (this->getColor() == 'w')
    {
        if (hasMoved)
        {
            if (dstRow == (srcRow - 1) && dstCol == srcCol &&
                board[dstRow][dstCol]->getName() == '#' ||
                dstRow == (srcRow - 1) && dstCol == (srcCol + 1) &&
                board[dstRow][dstCol]->getColor() == 'b' ||
                dstRow == (srcRow - 1) && dstCol == (srcCol - 1) &&
                board[dstRow][dstCol]->getColor() == 'b')
            {
                return true;
            }

        }
        else
        {
            if (dstRow == (srcRow - 2) && dstCol == srcCol &&
                board[dstRow + 1][dstCol]->getName() == '#' &&
                board[dstRow][dstCol]->getName() == '#' ||
                dstRow == (srcRow - 1) && dstCol == srcCol &&
                board[dstRow][dstCol]->getName() == '#' ||
                dstRow == (srcRow - 1) && dstCol == (srcCol + 1) &&
                board[dstRow][dstCol]->getColor() == 'w' ||
                dstRow == (srcRow - 1) && dstCol == (srcCol - 1) &&
                board[dstRow][dstCol]->getColor() == 'w')
            {
                return true;
            }
        }
    }
    return false;
}

bool Pawn::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    return false;
}

void Pawn::setHasMoved()
{
    this->hasMoved = true;
}
