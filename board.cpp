//
// Created by D00260463 on 24/04/2024.
//

#include "board.h"

board::board():w(9), h(9){}

void board::tap()
{
    for(auto current : bugs) //thank you clang-tidy
    {
        current->move();
    }
}

void board::addBug(bug* b)
{
    bugs.push_back(b);
}

bug* board::getBug(int i)
{
    return bugs.at(i);
}

int board::getWidth()
{
    return w;
}

int board::getHeight()
{
    return h;
}

vector<bug*> board::getBugs()
{
    return bugs;
}

bool board::hasBugAt(int x, int y)
{
    pair<int, int> refPos(x, y);
    bool hasBug = false;

    for(int i = 0; i<bugs.size(); i++)
    {
        if(bugs.at(i)->getPosition()==refPos)
        {
            hasBug = true;
        }
    }

    return hasBug;
}