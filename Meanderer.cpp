//
// Created by Hannah on 28/04/2024.
//

#include "Meanderer.h"
#include <sstream>

Meanderer::Meanderer(int id, int x, int y, int dir, int size):bug()
{
    this->id = id;
    this->position = pair<int, int>(x, y);
    this->direction = dir;
    this->size = size;
    this->alive = true;

    path.push_back(position);
}

void Meanderer::move()
{
    if(alive)
    {
        direction = ranDirection();
        while(isWayBlocked())
        {
            direction = ranDirection();
        }

        switch(direction){
            case 1: //north
                position.second--;
                break;
            case 2: //east
                position.first++;
                break;
            case 3: //south
                position.second++;
                break;
            case 4: //west
                position.first--;
                break;
        }

        path.push_back(position);
    }
}

void Meanderer::display()
{
    cout << id << " Meanderer (" << position.first << ", " << position.second << ") ";

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

    if(alive)
    {
        cout << "Alive" << endl;
    }
    else
    {
        cout << "Dead" << endl;
    }
}

string Meanderer::displayHistory()
{
    stringstream ss;
    ss << id << " Meanderer Path: " << historyToString() << " Alive: " << alive << endl;
    return ss.str();
}

string Meanderer::getType(){
    return "Meanderer";
}
