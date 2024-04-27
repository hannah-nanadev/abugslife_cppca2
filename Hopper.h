//
// Created by Hannah on 27/04/2024.
//

#ifndef ABUGSLIFE_HOPPER_H
#define ABUGSLIFE_HOPPER_H

#include "bug.h"

class Hopper: public bug{
public:
    Hopper(int id, int x, int y, int dir, int size, int hop);

protected:
    int hoplength;
};


#endif //ABUGSLIFE_HOPPER_H
