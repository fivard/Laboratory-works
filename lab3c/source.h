//
// Created by Admin on 27.03.2020.
//

#ifndef LAB3C_SOURCE_H
#define LAB3C_SOURCE_H

#include <iostream>
#include <ctime>
#include <vector>
#include <stack>

#define beginOfSubArray first
#define sizeOfSubArray second

using namespace std;

template <class T>
class Array {
    T* arr;
    int size;

public:
    Array(int newSize){
        arr = new T [newSize];
        size = newSize;
    }
    ~Array(){
        delete [] arr;
        cout << "destructor\n";
    }


    void timSort(){
        int minrun = GetMinrun();
        merge(split(minrun));
    }
    int GetMinrun()
    {
        int tempSize = size;
        int r = 0;
        while (tempSize >= 64) {
            r |= tempSize & 1;
            tempSize >>= 1;
        }
        return tempSize + r;
    }
    void insertionSort(int left, int right) {
        cout << "INSERTION SORT left-right = " << left << '-' << right << endl;
        T tempValue;
        for (int i = left + 1; i < right + 1; i++) {
            tempValue = arr[i];
            int j = i - 1;
            while (tempValue < arr[j] && j >= left) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = tempValue;
        }
    }
    vector<pair<int, int> > split(int minrun){
        vector<pair<int, int> > solution;

        int i = 0;
        while(i < size) {
            if (i + minrun >= size){
                solution.push_back({i, size - i});
                insertionSort(i, size -1);
                i = size;
            }else {
                pair<int, int> newPair(i, minrun);

                if (arr[i] >= arr[i + 1])
                    while (arr[i] >= arr[i + 1] && i < size)
                        i++;
                else
                    while (arr[i] < arr[i + 1] && i < size)
                        i++;

                if (i - newPair.beginOfSubArray > minrun)
                    newPair.sizeOfSubArray = i - newPair.beginOfSubArray;

                solution.push_back(newPair);
                insertionSort(newPair.beginOfSubArray, newPair.beginOfSubArray + newPair.sizeOfSubArray-1);
                i = newPair.beginOfSubArray + newPair.sizeOfSubArray;
            }
        }
        output();
        cout << "SubArrays\n";
        cout << "begin\tsize\n";
        for (auto i : solution)
            cout << i.first << '\t' << i.second << endl;
        cout << endl;
        return solution;
    }
    void merge(vector<pair<int, int> > pointerAndSize){
        vector<pair<int, int> > stack;

        for (int i = 0; i < pointerAndSize.size(); i++){
            stack.push_back(pointerAndSize[i]);
            cout << "Stack\nbegin\tsize\n";
            for (auto j : stack)
                cout << j.first << '\t' << j.second << endl;
            cout << endl;
            if (stack.size() > 2)
                while (!(stack[stack.size()-3].sizeOfSubArray > stack[stack.size()-2].sizeOfSubArray + stack[stack.size()-1].sizeOfSubArray || stack[stack.size()-2].sizeOfSubArray > stack[stack.size()-1].sizeOfSubArray)){
                    if (stack[stack.size()-2].sizeOfSubArray <= stack[stack.size()-1].sizeOfSubArray) {
                        pair<int, int> newSubArray = mergeSubArray(stack[stack.size()-1], stack[stack.size()-2]);
                        stack.pop_back();
                        stack.pop_back();
                        stack.push_back(newSubArray);
                    }
                    if (stack[stack.size()-3].sizeOfSubArray <= stack[stack.size()-2].sizeOfSubArray + stack[stack.size()-1].sizeOfSubArray)
                        if (stack[stack.size()-3].sizeOfSubArray < stack[stack.size()-1].sizeOfSubArray){
                            pair<int, int> last = stack[stack.size()-1];
                            pair<int, int> newSubArray = mergeSubArray(stack[stack.size()-3], stack[stack.size()-2]);
                            stack.pop_back();
                            stack.pop_back();
                            stack.pop_back();
                            stack.push_back(newSubArray);
                            stack.push_back(last);
                        }else{
                            pair<int, int> newSubArray = mergeSubArray(stack[stack.size()-1], stack[stack.size()-2]);
                            stack.pop_back();
                            stack.pop_back();
                            stack.push_back(newSubArray);
                        }
                    else
                        break;
                }
            if (stack.size() > 1)
                if (stack[stack.size()-2].sizeOfSubArray <= stack[stack.size()-1].sizeOfSubArray) {
                    pair<int, int> newSubArray = mergeSubArray(stack[stack.size()-1], stack[stack.size()-2]);
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(newSubArray);
                }
        }
        while(stack.size() > 1){
            pair<int, int> newSubArray = mergeSubArray(stack[stack.size()-1], stack[stack.size()-2]);
            stack.pop_back();
            stack.pop_back();
            stack.push_back(newSubArray);
        }
    }
    pair<int, int> mergeSubArray(pair<int, int> first, pair<int, int> second){
        int minSize, maxSize, minBegin, maxBegin;
        minBegin = min(first.beginOfSubArray, second.beginOfSubArray);
        maxBegin = max(first.beginOfSubArray, second.beginOfSubArray);
        if (minBegin == first.beginOfSubArray){
            minSize = first.sizeOfSubArray;
            maxSize = second.sizeOfSubArray;
        }else{
            minSize = second.sizeOfSubArray;
            maxSize = first.sizeOfSubArray;
        }

        int temporary[minSize];
        for (int i = 0; i < minSize; i++)
            temporary[i] = arr[minBegin+i];

        int temporaryPointer, subArrayPointer, arrayPointer;
        temporaryPointer = 0;
        subArrayPointer = maxBegin;
        arrayPointer = minBegin;

        while (temporaryPointer < minSize && subArrayPointer < maxBegin+maxSize) {
            if (temporary[temporaryPointer] < arr[subArrayPointer])
                arr[arrayPointer] = temporary[temporaryPointer++];
            else
                arr[arrayPointer] = arr[subArrayPointer++];
            arrayPointer++;
        }

        while (temporaryPointer < minSize) {
            arr[arrayPointer++] = temporary[temporaryPointer++];
        }

        cout << "MERGED " << first.first << '-' << first.second << " and " << second.first << '-' << second.second << endl;
        cout << "\tGOT " << minBegin << '-' << minSize+maxSize << endl << endl;
        return {minBegin, minSize+maxSize};
    }

    void generateArray() {
        srand(time(nullptr));
        for (int i = 0; i < size; i++)
            arr[i] = rand();
    }
    void copyTo(Array& second){
        for (int i = 0; i < size; i++)
            second.arr[i] = arr[i];
    }
    void output(){
        cout << "\nArray:\n";
        for (int i = 0; i < size; i++)
            cout << '\t' << i << ". " << arr[i] << endl;
    }
    void check(){
        int check = 0;
        for (int i = 1; i < size; i++)
            if (arr[i] < arr[i-1]) {
                cout << i-1 << ' ' << i << endl;
                check++;
            }
        cout << "Count of errors = " << check << endl << endl;
    }
};

void demonstration(){
    int size;
    cout << "Enter size\n";
    cin >> size;
    Array<int> first(size);
    first.generateArray();

    first.output();
    int minrun = first.GetMinrun();
    cout << "MinRun = " << minrun << endl;
    first.timSort();
    first.output();
    first.check();
    return;
};

void benchmark(){
    return;
};

#endif //LAB3C_SOURCE_H
