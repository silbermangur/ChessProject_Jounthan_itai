#include "Knight.h"

Knight::Knight(char name, char color) : Piece(name, color)
{

}

bool Knight::move(Piece* (&board)[8][8], int command[])
{
    if (command[3] == command[1] + 1 || command[3] == command[1] - 1)
    {
        if (command[2] == command[0] + 2 || command[2] == command[0] - 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (command[3] == command[1] + 2 || command[3] == command[1] - 2)
    {
        if (command[3] == command[1] + 1 || command[3] == command[1] - 1)
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
    return true;
}
