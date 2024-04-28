#include <iostream>
#include <fstream>
#include "board.h"
#include "bug.h"

using namespace std;
void sim(board bugBoard);

int main() {
    //Initialise board
    board b;

    //Start reading from file
    ifstream fin("bugs.txt");
    if(fin)
    {
        //Load bugs into board from file
        cout << "File opened successfully!" << endl;


        while(!fin.eof())
        {
            string line;
            getline(fin, line);
            cout << line << endl;
        }

    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    return 0;
}

void sim(board* bugBoard)
{

}
