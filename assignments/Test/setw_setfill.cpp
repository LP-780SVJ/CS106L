#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

void PrintTableHeader() {
    /*Print the ---...---+- pattern for all but the last column*/
    
    /*for (int column = 0; column < NUM_COLUMNS-1; ++column){
        for (int i = 0; i < COLUMN_WIDTH; ++i){
            cout << '-';
        }
        cout << "-+-``";
    }*/

    for (int column = 0; column < NUM_COLUMNS-1 ; ++column){
        cout << setfill('-') << setw(COLUMN_WIDTH) << "" << "-+-";
    }

    /*Now print the ---...--- pattern for the last column*/
    
    /*for(int k = 0; k < COLUMN_WIDTH; ++k){
        cout << '-';
    }
    cout << endl;*/

    cout << setw(COLUMN_WIDTH) << "" << setfill(' ') << endl;
    
}

void PrintTableBody() {
    ifstream input("table-data.txt");
    /*No error-checking here, but we should be sure to do this in any real program*/


    /*Loop over the lines in the file reading data*/
    
    /*for (int k=0; k<NUM_LINES; ++k){
        int intValue;
        double doubleValue;
        input >> intValue >> doubleValue;

        cout << setw(COLUMN_WIDTH) << (k+1) << " | "
             << setw(COLUMN_WIDTH) << intValue << " | "
             << setw(COLUMN_WIDTH) << doubleValue << endl;
    }*/

    int rowNumber = 0;
    while (true){
        //Use 'while(true) plus break', not 'while(!input.fail())'.
        //Use the "loop-and-a-half" idiom to avoid the need for an extra excution.
        int intValue;
        double doubleValue;
        input >> intValue >> doubleValue;

        if (input.fail()) break;

        cout << setw(COLUMN_WIDTH) << (rowNumber+1) << " | ";
        cout << setw(COLUMN_WIDTH) << intValue << " | ";
        cout << setw(COLUMN_WIDTH) << doubleValue << endl;

        rowNumber++;
    }

}


int main() {   
    PrintTableHeader();
    PrintTableBody();
    return 0;

    // cout << setw(10) << "hello" << endl;
    return 0;
}