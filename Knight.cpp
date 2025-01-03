#include "Knight.h"

bool Knight::move(int command[], bool isFirstTurn)
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
