#include "King.h"

bool King::move(int command[], bool isFirstTurn)
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
