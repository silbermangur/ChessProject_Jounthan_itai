#include "Knight.h"

Knight::Knight(char name, char color, std::string position) : Piece(name, color, position)
{

}

bool Knight::move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    if (destRow == row + 1 || destRow == row - 1)
    {
        if (destCol == col + 2 || destCol == col - 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (destRow == row + 2 || destRow == row - 2)
    {
        if (destCol == col + 1 || destCol == col - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
}

bool Knight::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    return false;
}
