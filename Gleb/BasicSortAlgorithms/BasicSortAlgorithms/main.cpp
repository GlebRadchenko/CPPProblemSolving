//
//  main.cpp
//  BasicSortAlgorithms
//
//  Created by Gleb Radchenko on 17.01.17.
//  Copyright © 2017 Gleb Radchenko. All rights reserved.
//

#include <iostream>
#include <vector>

#define DEBUG_MODE 1

using namespace std;

void print(vector<int>array) {
    cout << "\n";
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i];
        cout << " ";
    }
    cout << "\n";
}

#pragma mark - Get Random collection
vector<int> randomArray() {
    vector<int>array;
    int size = rand() % (DEBUG_MODE ? 30 : 200) + 1; // random size of array
    for (int i = 0; i < size; ++i) {
        int randomNumber = rand() % size + 1;
        array.push_back(randomNumber);
    }
    cout << "Array: ";
    if (DEBUG_MODE) { print(array); }
    return array;
}

#pragma mark - Bubble Sort
void bubbleSort(vector<int> &array, bool ascending) {
    for (int i = 0; i < array.size() - 1; ++i) {
        for (int j = i + 1; j < array.size(); ++j) {
            if (i == j || array[i] == array[j]) { continue; }
            if ((ascending && array[i] > array[j]) ||
                (!ascending && array[i] < array[j])) {
                std::swap(array[i], array[j]);
            }
        }
    }
    if (DEBUG_MODE) { print(array); }
    return;
}

#pragma mark - Merge Sort

vector<int> customMerge(vector<int> first, vector<int> second, bool ascending) {
    vector<int>result;
    
    int i = 0;
    int j = 0;
    
    while (i < first.size() && j < second.size()) {
        int firstElement = first[i];
        int secondElement = second[j];
        
        if (firstElement == secondElement) {
            result.push_back(firstElement);
            result.push_back(secondElement);
            ++i;
            ++j;
            continue;
        }
        
        if (ascending) {
            if (firstElement < secondElement) {
                result.push_back(firstElement);
                ++i;
            } else {
                result.push_back(secondElement);
                ++j;
            }
        } else {
            if (firstElement > secondElement) {
                result.push_back(firstElement);
                ++i;
            } else {
                result.push_back(secondElement);
                ++j;
            }
        }
    }
    
    if (i < first.size()) {
        for (int k = i; k < first.size(); ++k) {
            result.push_back(first[k]);
        }
    }
    
    if (j < second.size()) {
        for (int k = j; k < second.size(); ++k) {
            result.push_back(second[k]);
        }
    }
    return result;
}

void mergeSort(vector<int> &array, bool ascending) {
    if (array.size() <= 1) { return; }
    
    int halfSize = (int)array.size() / 2;
    vector<int> firstHalf(array.begin(), array.begin() + halfSize);
    vector<int> secondHalf(array.begin() + halfSize, array.end());
    
    mergeSort(firstHalf, ascending);
    mergeSort(secondHalf, ascending);
    
    array = customMerge(firstHalf, secondHalf, ascending);
    
    if (DEBUG_MODE) { print(array); }
    return;
}

#pragma mark - Quick Sort

void quickSort(vector<int> &array, int left, int right) {
    int middle = left + (right - left) / 2;
    int pivot = array[middle];
    
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (array[i] < pivot) { i++; }
        while (array[j] > pivot) { j--; }
        
        if (i <= j) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    
    if (i < right) { quickSort(array, i, right); }
    if (j > left) { quickSort(array, left, j); }
    
    if (DEBUG_MODE) { print(array); }
    return;
}

int main(int argc, const char * argv[]) {
    cout << "Bubble Sort: \n";
    vector<int>random1 = randomArray();
    bubbleSort(random1, true);
    
    cout << "Merge Sort: \n";
    vector<int>random2 = randomArray();
    mergeSort(random2, true);
    
    cout << "Quick Sort: \n";
    vector<int>random3 = randomArray();
    quickSort(random3, 0, (int)random3.size() - 1);
    
    return 0;
}
