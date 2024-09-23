/*Write a function HasHexLetters that accepts an int and returns whether or not that integer's*/
/*hexadecimal representation contains letters. (Hint: you'll need to use the hex and dec stream*/
/*manipulators in conjunction with a stringstream. Try to solve this problem without brute-forcing*/
/*it: leverage off the streams library instead of using loops.)*/

#include <iostream>
#include <sstream>

using namespace std;

bool HasHexLetters(int num) {
    stringstream ss;
    ss << hex << num;                               //hex 是一个格式化操控符，它指示流在输出数字时使用十六进制格式。
    string hexStr = ss.str();
    //cout << "Hexadecimal representation of " << num << " is " << hexStr << endl;
    for (char c : hexStr) {
        if (isalpha(c)) {
            return true;
        }
    }
    return false;
}

/*Answers*/
bool HasHexLetters_Ans(int value) {
    stringstream converter;
    converter << hex << value;
    int dummy;
    converter >> dec >> dummy;

    if(converter.fail()) {
        return true;
    }

    char leftover;
    converter >> leftover;

    return !converter.fail();
}

int main() {
    int num1 = 18;
    int num2 = 325235;
    int num3 = 235;
    int num4 = 1;
    int num5 = 2345;
    int num6 = 234231;
    

    cout << "num1: " << num1 << " has hex letters: " << (HasHexLetters(num1) ? "Yes" : "No") << endl;
    cout << "num2: " << num2 << " has hex letters: " << HasHexLetters(num2) << endl;
    cout << "num3: " << num3 << " has hex letters: " << HasHexLetters(num3) << endl;
    cout << "num4: " << num4 << " has hex letters: " << HasHexLetters(num4) << endl;
    cout << "num5: " << num5 << " has hex letters: " << HasHexLetters(num5) << endl;
    cout << "num6: " << num6 << " has hex letters: " << HasHexLetters(num6) << endl;

    cout << "num1: " << num1 << " has hex letters: " << (HasHexLetters_Ans(num1) ? "Yes" : "No") << endl;
    cout << "num2: " << num2 << " has hex letters: " << HasHexLetters_Ans(num2) << endl;
    cout << "num3: " << num3 << " has hex letters: " << HasHexLetters_Ans(num3) << endl;
    cout << "num4: " << num4 << " has hex letters: " << HasHexLetters_Ans(num4) << endl;
    cout << "num5: " << num5 << " has hex letters: " << HasHexLetters_Ans(num5) << endl;
    cout << "num6: " << num6 << " has hex letters: " << HasHexLetters_Ans(num6) << endl;
    

    return 0;

}