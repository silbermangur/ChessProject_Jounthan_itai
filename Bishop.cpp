#include "Bishop.h"

bool Bishop::move(int command[], bool isFirstTurn)
{
    if (command[1] - command[3] == (command[0] - command[2]) || (command[0] - command[2]) * -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
