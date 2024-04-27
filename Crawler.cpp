//
// Created by D00260463 on 24/04/2024.
//

#include "Crawler.h"

Crawler::Crawler(int id, int x, int y, int dir, int size):bug()
{
    this->id = id;
    this->position = pair<int, int>(x, y);
    this->direction = dir;
    this->size = size;

}

void Crawler::move()
{
    while(isWayBlocked())
    {
        direction = ranDirection();
    }
}