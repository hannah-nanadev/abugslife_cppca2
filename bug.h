//
// Created by D00260463 on 17/04/2024.
//
#include <iostream>
#include <list>
#ifndef ABUGSLIFE_BUG_H
#define ABUGSLIFE_BUG_H

using namespace std;
class bug {

protected:
    int id;
    pair<int, int> position;
    int direction; //TODO: replace with enum
    int size;
    bool alive;
    list<pair<int,int>> path;

public:
    virtual void move()=0;
    bool isWayBlocked();
};


#endif //ABUGSLIFE_BUG_H
