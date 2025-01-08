#include "King.h"

King::King(char name, char color) : Piece(name, color)
{

}

bool King::move(Piece* (&board)[8][8], int command[])
{
    if ((command[0] < command[2] && command[2] < command[0] + 2) && (command[1] < command[3] && command[3] < command[1] + 2))
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
    return true;
}
