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
    void tap();
    void addBug(bug* b);
    bug* getBug(int i);
    int getWidth();
    int getHeight();
    vector<bug*> getBugs();
    bool hasBugAt(int x, int y);
    vector<bug*> findBugsAt(int x, int y);
    void findBug(int id);

protected:
    //Width, height variables
    int w;
    int h;

    //Bug vector
    vector<bug*> bugs;
};
