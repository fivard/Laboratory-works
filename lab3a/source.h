//
// Created by Admin on 13.03.2020.
//

#ifndef LAB3A_SOURCE_H
#define LAB3A_SOURCE_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Point {

    double x, y, z;
public:
    Point();
    Point(double newX, double newY, double newZ);

    double getX();
    double getY();
    double getZ();
    int moreThan(Point another);
};

class ArrayOfPoints{
private:
    Point *arr;
    int size;
    int partition(int left, int right);
    void merge(int left, int middle, int right);

    int benchmarkPartition(int left, int right);
    void benchmarkMerge(int left, int middle, int right);

public:
    explicit ArrayOfPoints(int size);

    void generateArray();
    void copyTo(ArrayOfPoints newArray);
    void setAlreadySortedArray();
    void setAlreadySortedReversedArray();
    void output(int left, int right);

    void insertionSort(int left, int right);
    void quickSort(int left, int right); //Hoare's partition scheme, leftmost pivot
    void mergeSort(int left, int right); //Top down, two arrays
    void comboSort(int left, int right, const int& threshold);  //Based on mergeSort
                                                                //and insertionSort
    //without any output
    void benchmarkInsertionSort(int left, int right);
    void benchmarkQuickSort(int left, int right);
    void benchmarkMergeSort(int left, int right);
    void benchmarkComboSort(int left, int right, const int& threshold);
};

#endif //LAB3A_SOURCE_H
