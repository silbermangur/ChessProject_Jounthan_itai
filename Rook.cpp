#include "Rook.h"

Rook::Rook(char name, char color) : Piece(name, color)
{
}

bool Rook::move(Piece* (&board)[8][8], int command[])
{
    if (command[0] == command[2])
    {
        return true;
    }
    else if (command[1] == command[3])
    {
        return true;
    }
    return false;
}

bool Rook::isPieceInWay(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    // If it's a horizontal move (same row)
    if (row == destRow)
    {
        // Check left or right (depending on the direction of movement)
        if (col < destCol)
        {  // Moving right
            for (int i = col + 1; i <= destCol; ++i)
            {
                if (board[row][i]->getColor() == this->getColor())
                {
                    return false;  // Found same players piece in way
                }
            }
        }
        else if (col > destCol) {  // Moving left
            for (int i = col - 1; i >= destCol; --i)
            {
                if (board[row][i]->getColor() == this->getColor())
                {
                    return false;  // Found same players piece in way
                }
            }
        }
    }

    // If it's a vertical move (same column)
    else if (col == destCol)
    {
        // Check up or down (depending on the direction of movement)
        if (row < destRow)
        {  // Moving down
            for (int i = row + 1; i <= destRow; ++i)
            {
                if (board[i][col]->getColor() == this->getColor())
                {
                    return false;  // Found same players piece in way
                }
            }
        }
        else if (row > destRow)
        {  // Moving up
            for (int i = row - 1; i >= destRow; --i)
            {
                if (board[i][col]->getColor() == this->getColor())
                {
                    return false;  // Found same players piece in way
                }
            }
        }
    }

    // No opponent piece found in the line of sight
    return true;
}
