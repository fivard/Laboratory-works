//
// Created by Admin on 13.03.2020.
//

#include <algorithm>
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
int Point::moreThan(const Point& another) {
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
void ArrayOfPoints::copyTo(ArrayOfPoints& newArray) {
    for (int i = 0; i < size; i++)
        newArray.arr[i] = this->arr[i];
}
void ArrayOfPoints::setAlreadySortedArray() {
    for (int i = 0; i < size; i++)
        if ((i+1)%5 == 0) {
            Point point(i-5, i-5, i-5);
            arr[i] = point;
        }else{
            Point point(i, i, i);
            arr[i] = point;
        }
}
void ArrayOfPoints::setAlreadySortedReversedArray() {
    for (int i = 0; i < size; i++)
        if ((i+1)%5 == 0) {
            Point point(size-i+5, size-i+5, size-i+5);
            arr[i] = point;
        }else{
            Point point(size-i, size-i, size-i);
            arr[i] = point;
        }
}
void ArrayOfPoints::output(int left, int right) {
    for (int i = left; i <= right; i++)
        cout << i+1 << ". " << arr[i].getX() << ' ' << arr[i].getY() << ' ' << arr[i].getZ() << '\n';
}

void ArrayOfPoints::systemSort() {
    sort(arr, arr+size);
}
void ArrayOfPoints::insertionSort(int left, int right){
    cout << "INSERTION SORT\n";
    Point tempValue;
    for (int i = left+1; i < right+1; i++){
        tempValue = arr[i];
        int j = i-1;
        while (tempValue.moreThan(arr[j]) == -1 && j >= left){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tempValue;
        cout << "STEP " << i << endl;
        output(left, i);
        cout << endl;
        output(i+1, right);
        cout << endl;
    }
}
void ArrayOfPoints::quickSort(int left, int right) {
    if (left >= right) {
        cout << left << " and " << right << " is equal. Go next\n";
        return;
    }
    int delimiter = partition(left, right);
    quickSort(left, delimiter-1);
    quickSort(delimiter, right);
}
int ArrayOfPoints::partition(int left, int right) {
    cout << "partition " << left+1 << " and " << right+1 << endl;
    cout << "before:\n";
    output(left, right);
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
    cout << "\nafter:\n";
    output(left, right);
    cout << "delimiter = " << i+1 << endl << endl;
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
    cout << "\nmerge " << left+1 << "-" << middle+1
        << " and " << middle+2 << "-" << right+1 << endl;
    output(left, middle);
    cout << endl;
    output(middle+1, right);

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

    cout << "merged:\n";
    output(left, right);
}
void ArrayOfPoints::comboSort(int left, int right, const int& threshold) {
    if (left < right)
    {
        if (right-left <= threshold){
            insertionSort(left, right);
        }
        else {
            int middle = (left + right) / 2;
            cout << "splited up " << left+1 << "-" << middle+1
            << " and " << middle+2 << "-" << right+1 << endl;

            comboSort(left, middle, threshold);
            comboSort(middle + 1, right, threshold);

            merge(left, middle, right);
        }
    }
}

void ArrayOfPoints::benchmarkInsertionSort(int left, int right){
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
void ArrayOfPoints::benchmarkQuickSort(int left, int right) {
    if (left >= right)
        return;
    int delimiter = benchmarkPartition(left, right);
    benchmarkQuickSort(left, delimiter-1);
    benchmarkQuickSort(delimiter, right);
}
int ArrayOfPoints::benchmarkPartition(int left, int right) {
    Point pivot = arr[left];
    int i = left;
    int j = right;
    while (i <= j){
        while (pivot.moreThan(arr[i]) == 1 && i <= right)
            i++;
        while (arr[j].moreThan(pivot) == 1 && j >= left)
            j--;
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    return i;
}
void ArrayOfPoints::benchmarkMergeSort(int left, int right) {
    if (left < right)
    {
        int middle = (left+right)/2;

        benchmarkMergeSort(left, middle);
        benchmarkMergeSort(middle+1, right);

        benchmarkMerge(left, middle, right);
    }
}
void ArrayOfPoints::benchmarkMerge(int left, int middle, int right) {
    int i, j, k;
    int size1 = middle - left + 1;
    int size2 = right - middle;

    Point *L = new Point[size1];
    Point *R = new Point[size2];

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

    delete [] L;
    delete [] R;
}
void ArrayOfPoints::benchmarkComboSort(int left, int right, const int& threshold) {
    if (left < right)
    {
        if (right-left <= threshold){
            benchmarkInsertionSort(left, right);
        }
        else {
            int middle = (left + right) / 2;

            benchmarkComboSort(left, middle, threshold);
            benchmarkComboSort(middle + 1, right, threshold);

            benchmarkMerge(left, middle, right);
        }
    }
}
