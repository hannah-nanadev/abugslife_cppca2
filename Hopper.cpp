//
// Created by Hannah on 27/04/2024.
//

#include "Hopper.h"

Hopper::Hopper(int id, int x, int y, int dir, int size, int hop):bug()
{
    this->id = id;
    this->position = pair<int, int>(x, y);
    this->direction = dir;
    this->size = size;
    this->hoplength = hop;
}