#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int GetIneger(){
    while(true){    //Read input until user enters valid data
        stringstream converter;
        string input;
        getline (cin, input);
        converter << input;
        
        /*Try reading an int, continue if we succeeded*/
        int result;
        if(converter >> result){
            /*check that there isn't any leftover data*/
            char remaining;
            if(converter >> remaining){ //Something's left, input is invalid
                cout << "Unexpected character: " << remaining << endl;
            }
            else{
                return result;
            }
        }
        else{
            cout << "Please enter a valid integer: " << endl;
        }
        cout << "Retry: ";

    }
}

int main(){
    int num = GetIneger();
    cout << "You entered: " << num << endl;
    return 0;
}