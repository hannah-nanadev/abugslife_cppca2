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
    switch(input) {
        case 1: {//Tap
            bugBoard.tap();
            dispBoard(bugBoard);
            return true;
        }
        case 2: {//Bug info
            for (int i = 0; i < bugBoard.getBugs().size(); i++) {
                bugBoard.getBug(i)->display();
            }
            return true;
        }
        case 3: {//Find by ID
            cout << "Enter bug ID >";
            int input;
            cin >> input;
            bugBoard.findBug(input);
            return true;
        }
        case 4: {//Display History
            for (int i = 0; i < bugBoard.getBugs().size(); i++) {
                cout << bugBoard.getBug(i)->displayHistory();
            }
            return true;
        }
        case 5: { //Display Cells
            for(int y = 0; y<=bugBoard.getHeight(); y++)
            {
                for(int x = 0; x<=bugBoard.getWidth(); x++)
                {
                    cout << "(" << x << "," << y << "): ";
                    if(bugBoard.hasBugAt(x, y))
                    {
                        vector<bug*> foundBugs = bugBoard.findBugsAt(x, y);
                        for(int i = 0; i<foundBugs.size(); i++)
                        {
                            cout << foundBugs.at(i)->getType() << " " << foundBugs.at(i)->getID() << ", ";
                        }
                        cout << endl;
                    }
                    else
                    {
                        cout << "empty" << endl;
                    }
                }
            }
            return true;
        }
        case 6: { //Exit
            ofstream out("bugs_life_history_date_time.out");
            if(out)
            {
                for (int i = 0; i < bugBoard.getBugs().size(); i++) {
                    out << bugBoard.getBug(i)->displayHistory();
                }
                cout << "Life history saved to bugs_life_history_date_time.out" << endl;
            }
            else
            {
                cout << "Unable to save life history.";
            }
            return false;
        }
        default: {
            return true;
        }
    }
}