//
// Created by Admin on 13.03.2020.
//

#include "source.h"

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}
Point::Point(double newX, double newY, double newZ) {
    x = newX;
    y = newY;
    z = newZ;
}

double Point::getX() {
    return x;
}
double Point::getY() {
    return y;
}
double Point::getZ() {
    return z;
}
int Point::moreThan(Point another) {
    if (this->x > another.x)
        return 1;
    else if (this->x < another.x)
        return -1;

    if (this->y > another.y)
        return 1;
    else if (this->y < another.y)
        return -1;

    if (this->z > another.z)
        return 1;
    else if (this->z < another.z)
        return -1;

    return 0;
}

ArrayOfPoints::ArrayOfPoints(int size){
    this->size = size;
    arr = new Point [size];
}

void ArrayOfPoints::generateArray() {
    srand(time(nullptr));
    for (int i = 0; i < size; i++){
        double x = (double)rand()/RAND_MAX + rand()%100;
        double y = (double)rand()/RAND_MAX + rand()%100;
        double z = (double)rand()/RAND_MAX + rand()%100;
        Point tempPoint(x,y,z);
        arr[i] =tempPoint;
    }
}
void ArrayOfPoints::setStaticValue(int value) {
    Point a(value, value, value);
    for (int i = 0; i < size; i++)
        arr[i] = a;
}
void ArrayOfPoints::output() {
    for (int i = 0; i < size; i++)
        cout << i << ". " << arr[i].getX() << ' ' << arr[i].getY() << ' ' << arr[i].getZ() << '\n';
}

void ArrayOfPoints::insertionSort(int left, int right){
    Point tempValue;
    for (int i = left+1; i < right+1; i++){
        tempValue = arr[i];
        int j = i-1;
        while (tempValue.moreThan(arr[j]) == -1 && j >= left){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tempValue;
    }
}
void ArrayOfPoints::quickSort(int left, int right) {
    if (left >= right)
        return;
    int delimiter = partition(left, right);
    quickSort(left, delimiter-1);
    quickSort(delimiter, right);
}
int ArrayOfPoints::partition(int left, int right) {
    Point pivot = arr[left];
    int i = left;
    int j = right;
    while (i <= j){
        while (pivot.moreThan(arr[i]) == 1)
            i++;
        while (arr[j].moreThan(pivot) == 1)
            j--;
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    return i;
}
void ArrayOfPoints::mergeSort(int left, int right) {
    if (left < right)
    {
        int middle = (left+right)/2;

        mergeSort(left, middle);
        mergeSort(middle+1, right);

        merge(left, middle, right);
    }
}
void ArrayOfPoints::merge(int left, int middle, int right) {
    int i, j, k;
    int size1 = middle - left + 1;
    int size2 = right - middle;

    Point L[size1], R[size2];

    for (i = 0; i < size1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < size2; j++)
        R[j] = arr[middle + 1+ j];

    i = j = 0;
    k = left;
    while (i < size1 && j < size2){
        if (L[i].moreThan(R[j]) <= 0)
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    while (i < size1)
        arr[k++] = L[i++];

    while (j < size2)
        arr[k++] = R[j++];
}
void ArrayOfPoints::comboSort(int left, int right, const int& threshold) {
    if (left < right)
    {
        if (right-left <= threshold){
            insertionSort(left, right);
        }
        else {
            int middle = (left + right) / 2;

            comboSort(left, middle, threshold);
            comboSort(middle + 1, right, threshold);
            merge(left, middle, right);
        }
    }
}