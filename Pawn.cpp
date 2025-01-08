#include "Pawn.h"

Pawn::Pawn(char name, char color) : Piece(name, color)
{
}

bool Pawn::move(Piece* (&board)[8][8], int command[])
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
    if (command[0] == command[2])
    {
        if (command[3] == command[1] + one)
        {
            return true;
        }
        else if (command[3] == command[1] + two)
        {
            if (command[1] != pawnStartPos)
            {
                return false;
            }
            return isPieceInWay(board, command[1], command[0], command[3], command[2]);
        }
        return false;
    }
    else
    {
        if (command[2] == command[0] + 1 || command[2] == command[0] - 1)
        {
            if (command[3] == command[1] + one)
            {
                if (board[command[3]][command[2]]->getColor() != (board[command[1]][command[0]]->getColor()) && ('#'))
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
    int one = 1;
    if (this->getColor() == 'b')
    {
        one = -1;
    }
    if (board[row + one][col]->getName() == '#')
    {
        return true;
    }
    return false;
}
