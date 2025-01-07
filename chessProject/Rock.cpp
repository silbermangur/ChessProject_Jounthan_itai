#include "Rock.h"

bool Rock::mov(string command ,Piece* (&board)[8][8])
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

bool Rock::isPieceInWay(string command, Piece* (&board)[8][8], int row, int col,
    int destRow, int destCol)
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

bool Rock::isCheck(Piece* (&board)[8][8], int destRow, int destCol)
{
    for (int i = 0; i < 8; i++)
    {
        if (board[destRow][i]->getColor() != this->getColor() 
            && board[destRow][i]->getName() == 'k' || 
            board[destRow][i]->getColor() != this->getColor()
            && board[destRow][i]->getName() == 'K')
        {
            return true;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (board[i][destCol]->getColor() != this->getColor() 
            && board[i][destCol]->getName() == 'k' ||
            board[i][destCol]->getColor() != this->getColor()
            && board[i][destCol]->getName() == 'K')
        {
            return true;
        }
    }
    return false;
}



