#include "Pawn.h"

bool Pawn::move(int command[], bool isFirstTurn)
{
    if (command[3] == command[1] + 1)
    {
        return true;
    }

    else if (command[3] == command[1] + 2)
    {
        if (isFirstTurn)
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
