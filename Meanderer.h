//
// Created by Hannah on 28/04/2024.
//

#ifndef ABUGSLIFE_MEANDERER_H
#define ABUGSLIFE_MEANDERER_H
#include "bug.h"


class Meanderer:public bug {
public:
    Meanderer(int id, int x, int y, int dir, int size);
    void move() override;
    void display() override;
    string displayHistory() override;
    string getType() override;
};


#endif //ABUGSLIFE_MEANDERER_H
