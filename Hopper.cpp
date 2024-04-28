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
    this->alive = true;

    path.push_back(position);
}

void Hopper::move()
{
    if(alive)
    {
        while(isWayBlocked())
        {
            direction = ranDirection();
        }

        switch(direction){
            case 1: //north
                position.second+hoplength;
                if(position.second>9)
                {
                    position.second = 9;
                }
                break;
            case 2: //east
                position.first+hoplength;
                if(position.first>9)
                {
                    position.first = 9;
                }
                break;
            case 3: //south
                position.second-hoplength;
                if(position.second<0)
                {
                    position.second=0;
                }
                break;
            case 4: //west
                position.first-hoplength;
                if(position.first<0)
                {
                    position.second=0;
                }
                break;
        }

        path.push_back(position);
    }
}

void Hopper::display()
{
    cout << id << " Hopper (" << position.first << ", " << position.second << ") ";

    switch(direction){
        case 1: //north
            cout << "North ";
            break;
        case 2: //east
            cout << "East ";
            break;
        case 3: //south
            cout << "South ";
            break;
        case 4: //west
            cout << "West ";
            break;
    }

    cout << hoplength;

    if(alive)
    {
        cout << " Alive" << endl;
    }
    else
    {
        cout << " Dead" << endl;
    }
}