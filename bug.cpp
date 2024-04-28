//
// Created by D00260463 on 17/04/2024.
//

#include "bug.h"
#include <random>

using namespace std;

bool bug::isWayBlocked()
{
    if(position.first==9&&direction==2||
    position.first==0&&direction==4||
    position.second==0&&direction==1||
    position.second==9&&direction==3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int bug::ranDirection()
{
    return rand()%3+1;
}

pair<int, int> bug::getPosition()
{
    return position;
}
