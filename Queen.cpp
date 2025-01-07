#include "Queen.h"

bool Queen::move(int command[], bool isFirstTurn)
{
    if (command[1] != command[3])
    {
        if (command[0] == command[2])
        {
            return true;
        }
        else if (command[1] - command[3] == (command[0] - command[2]) || (command[0] - command[2]) * -1)
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
    }
    else
    {
        return false;
    }
}
