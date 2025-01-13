#include "Rook.h"

Rook::Rook(char name, char color, std::string position) : Piece(name, color, position)
{
}

bool Rook::move(Piece* (&board)[8][8], int row, int col, int destRow, int destCol)
{
    if (row == destRow || col == destCol)
    {
        return true;
    }
    return false;
}

bool Rook::isPieceInWay(Piece* (&board)[8][8], int row, int col,
    int destRow, int destCol)
{
    // If it's a horizontal move (same row)
    if (row == destRow) 
    {
        // Check left or right (depending on the direction of movement)
        if (col < destCol) 
        {  // Moving right
            for (int i = col + 1; i < destCol && i < 7; ++i)
            {
                if(board[row][i]->getName() != '#')
                {
                    return true;
                }
            }
        }
        else if (col > destCol) 
        {  // Moving left
            for (int i = col - 1; i > destCol && i >0; --i) 
            {
                if (board[row][i]->getName() != '#')
                {
                    return true;  
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
            for (int i = row + 1; i < destRow && i < 7; ++i)
            {
              
                if (board[i][col]->getName() != '#')
                {
                    return true;  
                }

            }
        }
        else if (row > destRow) 
        {  // Moving up
            for (int i = row - 1; i > destRow && i > 0; --i)
            {
                if (board[i][col]->getName() != '#')
                {
                    return true;  
                }
            }
        }
    }
    // No opponent piece found in the line of sight
    return false;
} 

