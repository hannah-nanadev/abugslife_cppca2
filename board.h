//
// Created by D00260463 on 24/04/2024.
//

#ifndef ABUGSLIFE_BOARD_H
#define ABUGSLIFE_BOARD_H

#endif //ABUGSLIFE_BOARD_H

#include <vector>
#include "bug.h"

using namespace std;
class board{

public:
    board();
    board(int w, int h)
    vector<bug*> bugs;
    void tap(){};

protected:
    //Width, height variables
    int w;
    int h;
};