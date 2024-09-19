#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {    
    ofstream myfile;
    myfile.open("myFile.txt");
    myfile << "Hello, world!" << endl;
    myfile.close();
    return 0;
}