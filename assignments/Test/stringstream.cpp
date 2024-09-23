#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // int levelNum = 10;
    // stringstream ss;
    // ss << "Level " << levelNum;
    // string levelStr = ss.str();
    // cout << levelStr << endl;
    // return 0;

    stringstream ss;
    int mtInt;
    double mtDouble;
    string mtString;
    ss << "123 456.789 hello";                  //Insert string data
    ss >> mtInt >> mtDouble >> mtString;        //Extract mixed data
    cout << "mtInt: " << mtInt << endl;
    cout << "mtDouble: " << mtDouble << endl;
    cout << "mtString: " << mtString << endl;
    return 0;
}