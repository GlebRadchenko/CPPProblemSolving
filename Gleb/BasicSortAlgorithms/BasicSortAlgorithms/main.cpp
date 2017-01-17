//
//  main.cpp
//  BasicSortAlgorithms
//
//  Created by Gleb Radchenko on 17.01.17.
//  Copyright © 2017 Gleb Radchenko. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>array) {
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i];
        cout << " ";
    }
    cout << "\n";
}

#pragma mark - Get Random collection
vector<int> randomArray() {
    std::vector<int>array;
    int size = rand() % 20 + 1; // random size of array
    
    for (int i = 0; i < size; ++i) {
        int randomNumber = rand() % 50 + 1;
        array.push_back(randomNumber);
    }
    cout << "Array: ";
    print(array);
    return array;
}

#pragma mark - Simple implementation of Bubble Sort without optimization
void bubbleSort(std::vector<int> &array, bool ascending) {
    for (int i = 0; i < array.size() - 1; ++i) {
        for (int j = i + 1; j < array.size(); ++j) {
            if (i == j || array[i] == array[j]) { continue; }
            if ((ascending && array[i] > array[j]) ||
                (!ascending && array[i] < array[j])) {
                std::swap(array[i], array[j]);
            }
        }
    }
    print(array);
    return;
}

int main(int argc, const char * argv[]) {
    cout << "Bubble Sort: \n";
    vector<int>random = randomArray();
    bubbleSort(random, true);
    
    return 0;
}
