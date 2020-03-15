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
public:
    explicit ArrayOfPoints(int size);

    void generateArray();
    void setStaticValue(int value);
    void output();

    void insertionSort(int left, int right);
    void quickSort(int left, int right); //Hoare's partition scheme, leftmost pivot
    int partition(int left, int right);
    void mergeSort(int left, int right); //Top down, two arrays
    void merge(int left, int middle, int right);
    void comboSort(int left, int right, const int& threshold); //Based on merge sort
};

#endif //LAB3A_SOURCE_H
