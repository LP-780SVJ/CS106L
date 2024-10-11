#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;
void SlectionSort(vector<int>& values);
auto GetSmallestIndex(vector<int>& values, size_t start) -> size_t;
auto GetIneger() -> int;
auto InsertionIndex(vector<int>& values, int toInsert) -> size_t;

const int K_NUM_VALUES = 10;

auto main(int /*unused*/, char** /*unused*/) -> int{
    vector<int> values;

    for(int i = 0; i < K_NUM_VALUES; ++i){
        cout << "Enter another value: ";
        int val = GetIneger();

        /*Insert the element at the correct position in the sorted vector*/
        values.insert(values.begin() + InsertionIndex(values, val), val);
    }

    //SelectionSort(values);

    for(size_t i=0; i < K_NUM_VALUES; ++i) {
        cout << values[i] << " " << endl;
}

    return 0;
}

void SelectionSort(vector<int>& values){
    for(size_t i=0; i < values.size(); ++i){
        size_t smallest_index = GetSmallestIndex(values, i);
        swap(values[i], values[smallest_index]);
    }
}

auto GetSmallestIndex(vector<int>& values, size_t start) -> size_t{
    size_t smallest_index = start;
    for(size_t i=start; i < values.size(); ++i){
        if(values[i] < values[smallest_index]){
            smallest_index = i;
        }
    }
    return smallest_index;
}

auto GetIneger() -> int{
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

auto InsertionIndex(vector<int>& values, int toInsert) -> size_t{
    for(size_t i=0; i < values.size(); ++i){
        if(toInsert < values[i]){
            return i;
        }
    }
    return values.size();
}