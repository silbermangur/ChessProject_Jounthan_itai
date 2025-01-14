#include "Pawn.h"

Pawn::Pawn(char name, char color, std::string position) : Piece(name, color, position)
{
}

bool Pawn::move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    int one = 1;
    int two = 2;
    int pawnStartPos = 2;

    if (this->getColor() == 'b')
    {
        one = -1;
        two = -2;
        pawnStartPos = 7;
    }
    if (col == destCol)
    {
        if (destRow == row + one)
        {
            return true;
        }
        else if (destRow == row + two)
        {
            if (row != pawnStartPos)
            {
                return false;
            }
            return true;
        }
        return false;
    }
    else
    {
        if (destCol == col + 1 || destCol == col - 1)
        {
            if (destRow == row + one)
            {
                if (board[destRow - 1][destCol - 1]->getColor() != board[row - 1][col - 1]->getColor() && board[destRow - 1][destCol - 1]->getColor() != '#')
                {
                    return true;
                }
            }
            return false;
        }
    }
}

bool Pawn::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    if (col != destCol)
    {
        return false;
    }
    int one = 1;
    if (this->getColor() == 'b')
    {
        one = -1;
    }
    if (board[row + one][col]->getName() == '#')
    {
        return false;
    }
    return true;
}
