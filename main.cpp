#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
#include "bug.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;
bug* parseBug(string &pbug);
void runBoard(board& bugBoard);
bool hasBug(int x, int y, vector<bug*> bugs);

//Initialisation function
int main() {
    //Initialise board
    board b;

    //Start reading from file
    ifstream fin("bugs.txt");
    if(fin)
    {
        //Load bugs into board from file
        cout << "File opened successfully!" << endl;

        //Read lines one by one and add bugs to vector
        while(!fin.eof())
        {
            string line;
            getline(fin, line);
            b.addBug(parseBug(line));
        }

        runBoard(b);

    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    return 0;
}

//Sub-initialisation function (reads bugs into vector)
bug* parseBug(string &pbug)
{
    stringstream sstr(pbug);
    const char delim = ';';

    //Initialise fields
    string type;
    vector<int> fields;
    //Insert values into fields
    getline(sstr, type, delim);

    while(!sstr.eof())
    {
        string temp;
        getline(sstr, temp, delim);
        int num = stoi(temp);
        fields.push_back(num);
    }

    bug* prototype;

    if(type=="H")
    {
        prototype = new Hopper
                (fields.at(0), fields.at(1), fields.at(2), fields.at(3), fields.at(4), fields.at(5));
        return prototype;
    }
    else if(type=="C")
    {
        prototype = new Crawler
                (fields.at(0), fields.at(1), fields.at(2), fields.at(3), fields.at(4));
        return prototype;
    }
    else
    {
        return nullptr;
    }
}

//Main runtime function
void runBoard(board& bugBoard)
{

}
