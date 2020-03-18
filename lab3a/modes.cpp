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
    const int size = 10000;
    int threshold = 15;
    ArrayOfPoints workingArray(size);

    cout << "Size = " << size << ". Random array time:\n";
    randomArray(workingArray, size, threshold);

    cout << "\nSize = " << size << ". Already sorted array time:\n";
    alreadySortedArray(workingArray, size, threshold);

    cout << "\nSize = " << size << ". Already sorted reversed array time:\n";
    alreadySortedReversedArray(workingArray, size, threshold);

    cout << "\nLet's find the best threshold for jump from merge sort to insertion sort\n";
    betterThreshold();
}

void randomArray(ArrayOfPoints workingArray, int size, const int& threshold){
    ArrayOfPoints buffer(size);
    workingArray.generateArray();
    workingArray.copyTo(buffer);

    cout << "InsertionSort: " << timeInsertionSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "MergeSort: " << timeMergeSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "QuickSort: " << timeQuickSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "ComboSort(threshold = " << threshold << "): " <<  timeComboSort(workingArray, size, 150) << endl;
    buffer.copyTo(workingArray);
}
void alreadySortedArray(ArrayOfPoints workingArray, int size, const int& threshold){
    ArrayOfPoints buffer(size);
    workingArray.setAlreadySortedArray();
    workingArray.copyTo(buffer);

    cout << "InsertionSort: " << timeInsertionSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "MergeSort: " << timeMergeSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "QuickSort: " << timeQuickSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "ComboSort(threshold = " << threshold << "): " <<  timeComboSort(workingArray, size, 150) << endl;
    buffer.copyTo(workingArray);
}
void alreadySortedReversedArray(ArrayOfPoints workingArray, int size, const int& threshold){
    ArrayOfPoints buffer(size);
    workingArray.setAlreadySortedReversedArray();
    workingArray.copyTo(buffer);

    cout << "InsertionSort: " << timeInsertionSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "MergeSort: " << timeMergeSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "QuickSort: " << timeQuickSort(workingArray, size) << endl;
    buffer.copyTo(workingArray);

    cout << "ComboSort(threshold = " << threshold << "): " << timeComboSort(workingArray, size, 150) << endl;
    buffer.copyTo(workingArray);
}
void betterThreshold(){
    const int size = 100000;
    cout << "Size = " << size << '\n';

    ArrayOfPoints workingArray(size), buffer(size);
    workingArray.generateArray();
    workingArray.copyTo(buffer);

    for (int i = 3; i < 500; i+=50) {
        cout << "Threshold = " << i << ". Time for ComboSort = "
        << timeComboSort(workingArray, size, i) << endl;
        buffer.copyTo(workingArray);
    }
    cout << "\nThe more is threshold, the more is time. Let's find between 10 and 200\n\n";
    for (int i = 10; i < 200; i+=10) {
        cout << "Threshold = " << i << ". Time for ComboSort = "
             << timeComboSort(workingArray, size, i) << endl;
        buffer.copyTo(workingArray);
    }

    cout << "\nLet's find between 10 and 100 with 10 times for each threshold\n\n";
    double minimumBetween10And100 = 1000;
    int leftBorder;
    for (int i = 10; i < 100; i+=10) {
        double medium = 0;
        cout << "Threshold = " << i << endl;
        for (int j = 0; j < 10; j++){
            double tempTime = timeComboSort(workingArray, size, j);
            cout << '\t' << tempTime << endl;
            buffer.copyTo(workingArray);
            medium += tempTime;
        }
        cout << "Medium time = "
             << medium/10 << endl << endl;
        if (medium/10 < minimumBetween10And100){
            minimumBetween10And100 = medium/10;
            leftBorder = i;
        }
    }

    cout << "\nLet's find between " << leftBorder << " and " << leftBorder+10
    << " with 10 times for each threshold\n\n";
    double minimumTime = 1000;
    int threshold;
    for (int i = leftBorder; i < leftBorder+10; i++) {
        double medium = 0;
        cout << "Threshold = " << i << endl;
        for (int j = 0; j < 10; j++){
            double tempTime = timeComboSort(workingArray, size, j);
            cout << '\t' << tempTime << endl;
            buffer.copyTo(workingArray);
            medium += tempTime;
        }
        cout << "Medium time = "
             << medium/10 << endl << endl;
        if (medium/10 < minimumTime){
            minimumTime = medium/10;
            threshold = i;
        }
    }

    cout << "THRESHOLD = " << threshold << endl;
}

double timeInsertionSort(ArrayOfPoints arr, int size){
    double startInsertionSort = clock();
    arr.benchmarkInsertionSort(0, size-1);
    double endInsertionSort = clock();
    double timeInsertionSort = (endInsertionSort - startInsertionSort) / CLOCKS_PER_SEC;
    return timeInsertionSort;
}
double timeMergeSort(ArrayOfPoints arr, int size){
    double startMergeSort = clock();
    arr.benchmarkMergeSort(0, size-1);
    double endMergeSort = clock();
    double timeMergeSort = (endMergeSort - startMergeSort) / CLOCKS_PER_SEC;
    return timeMergeSort;
}
double timeQuickSort(ArrayOfPoints arr, int size){
    double startQuickSort = clock();
    arr.benchmarkQuickSort(0, size-1);
    double endQuickSort = clock();
    double timeQuickSort = (endQuickSort - startQuickSort) / CLOCKS_PER_SEC;
    return timeQuickSort;
}
double timeComboSort(ArrayOfPoints arr, int size, const int& threshold){
    double startComboSort = clock();
    arr.benchmarkComboSort(0, size-1, threshold);
    double endComboSort = clock();
    double timeComboSort = (endComboSort - startComboSort) / CLOCKS_PER_SEC;
    return timeComboSort;
}