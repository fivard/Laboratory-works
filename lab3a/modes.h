//
// Created by Admin on 15.03.2020.
//

#ifndef LAB3A_MODES_H
#define LAB3A_MODES_H

#include "source.h"

void demonstration();

void benchmark();

void randomArray(ArrayOfPoints workingArray, int size, const int& threshold);
void alreadySortedArray(ArrayOfPoints workingArray, int size, const int& threshold);
void alreadySortedReversedArray(ArrayOfPoints workingArray, int size, const int& threshold);
void betterThreshold();

double timeInsertionSort(ArrayOfPoints arr, int size);
double timeMergeSort(ArrayOfPoints arr, int size);
double timeQuickSort(ArrayOfPoints arr, int size);
double timeComboSort(ArrayOfPoints arr, int size, const int& threshold);

#endif //LAB3A_MODES_H
