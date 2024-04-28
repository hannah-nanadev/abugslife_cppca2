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