//
// Created by Admin on 15.03.2020.
//

#include "modes.h"

void demonstration(){
    cout << "Size is equal to 10 for better demonstration each steps of sotrs\n";
    int size = 10;

    ArrayOfPoints workingArray(size), buffer(size);
    workingArray.generateArray();
    workingArray.copyTo(buffer);

    cout << "Have array with " << size << " elements:\n";
    workingArray.output(0, size-1);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << "\nSorted by insertionSort\n";
    workingArray.insertionSort(0, size-1);
    cout << "Sorted:\n";
    workingArray.output(0, size-1);
    buffer.copyTo(workingArray);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << "\nSorted by quickSort\n";
    workingArray.quickSort(0, size-1);
    cout << "Sorted:\n";
    workingArray.output(0, size-1);
    buffer.copyTo(workingArray);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << "\nSorted by mergeSort\n";
    workingArray.mergeSort(0, size-1);
    cout << "Sorted:\n";
    workingArray.output(0, size-1);
    buffer.copyTo(workingArray);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    cout << "\nSorted by comboSort. Threshold = 3\n";
    workingArray.comboSort(0, size-1, 3);
    cout << "Sorted:\n";
    workingArray.output(0, size-1);
    buffer.copyTo(workingArray);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void benchmark(){
    int size = 10000;
    ArrayOfPoints alreadySorted(size), alreadySortedReversed(size);
    alreadySorted.setAlreadySortedArray();
    alreadySortedReversed.setAlreadySortedReversedArray();
    alreadySorted.output(0, size-1);
}