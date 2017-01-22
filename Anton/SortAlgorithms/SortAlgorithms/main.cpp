//
//  main.cpp
//  SortAlgorithms
//
//  Created by Anton Poltoratskyi on 22.01.17.
//  Copyright © 2017 Anton Poltoratskyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


#pragma mark - Bubble Sort

void bubbleSort(vector<int> &array) {
    
    for (int i = 0; i < array.size(); i++) {
        for (int j = i + 1; j < array.size(); j++) {
            
            if (array[j] < array[i]) {
                swap(array[i], array[j]);
            }
        }
    }
}


#pragma mark - Test Data

vector<int>testArray() {
    
    vector<int> array;
    
    int maxValue = 100;
    int size = 10;
    
    for (int i = 0; i < size; i++) {
        array.push_back(rand() % maxValue + 1);
    }
    return array;
}


#pragma mark - Utils

void swap(int &obj1, int &obj2) {
    int temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

void print(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i];
        cout << " ";
    }
    cout << "\n";
}


#pragma mark - Main

int main(int argc, const char * argv[]) {
    
    vector<int> array = testArray();
    print(array);
    
    bubbleSort(array);
    print(array);
    
    return 0;
}
