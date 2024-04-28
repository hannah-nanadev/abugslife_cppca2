//
// Created by D00260463 on 24/04/2024.
//

#ifndef ABUGSLIFE_CRAWLER_H
#define ABUGSLIFE_CRAWLER_H
#include "bug.h"

class Crawler:public bug{
public :
    Crawler(int id, int x, int y, int dir, int size);
    void move() override;
    void display() override;
    string displayHistory() override;
};


#endif //ABUGSLIFE_CRAWLER_H
