#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
#include "bug.h"
#include "Crawler.h"
#include "Hopper.h"



using namespace std;
bug* parseBug(string &pbug);
void dispBoard(board& bugBoard);
bool menu(board& bugBoard);

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

        dispBoard(b);
        bool run = menu(b);
        while(run)
        {
            run = menu(b);
        }
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
                (fields.at(0), fields.at(1), fields.at(2), fields.at(3), fields.at(4),
                 fields.at(5));
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
        cout << "Invalid bug data." << endl;
        terminate();
    }
}

//Board display function
void dispBoard(board& bugBoard) //Ordinarily this would use an SFML GUI. However, due to time constraints, this won't.
{
    for(int y = 0; y<=bugBoard.getHeight(); y++)
    {
        for(int x = 0; x<=bugBoard.getWidth(); x++)
        {
            if(bugBoard.hasBugAt(x, y))
            {
                cout << "X   ";
            }
            else
            {
                cout << "-   ";
            }
        }
        cout << endl;
    }
}

bool menu(board& bugBoard)
{
    cout << "1 - Tap board" << endl;
    cout << "2 - Display Bug Info" << endl;
    cout << "3 - Find Bug by ID" << endl;
    cout << "4 - Display History" << endl;
    cout << "5 - Display Cells" << endl;
    cout << "6 - Exit" << endl;

    int input;
    cin >> input;
    switch(input){
        case 1:
            bugBoard.tap();
            dispBoard(bugBoard);
            return true;
        case 2:
            for(int i = 0; i<bugBoard.getBugs().size(); i++)
            {
                bugBoard.getBug(i)->display();
            }
            return true;
        case 3:
            return true;
        case 4:
            return true;
        case 5:
            return true;
        case 6:
            return false;
        default:
            return true;
    }
}