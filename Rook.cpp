#include "Rook.h"

bool Rook::move(int command[], bool isFirstTurn)
{
    if (command[1] != command[3])
    {
        if (command[0] == command[2])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (command[0] != command[2])
    {
        if (command[1] == command[3])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
