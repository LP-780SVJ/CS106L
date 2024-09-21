#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    ifstream capitals("world-capitals.txt");
    if (!capitals.is_open()) {
        cerr << "Error: could not open file" << endl;
        return -1;
    }

    /*while (true){
        string capital, country;
        getline(capitals, capital);
        getline(capitals, country);

        if (capitals.fail()){
            break;
        }

        cout << capital << " is the capital of " << country << endl;
    }*/
    //It's clunky!!!

    
    //Use loop-and-a-half approach!!!
    string capital, country;
    while (getline(capitals, capital) && getline(capitals, country)){
        cout << capital << " is the capital of " << country << endl;
    }
    return 0;
}