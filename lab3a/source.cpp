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
        double x = (double)rand()/RAND_MAX + rand();
        double y = (double)rand()/RAND_MAX + rand();
        double z = (double)rand()/RAND_MAX + rand();
        Point tempPoint(x,y,z);
        arr[i] =tempPoint;
    }
}

void ArrayOfPoints::output() {
    for (int i = 0; i < size; i++)
        cout << arr[i].getX() << ' ' << arr[i].getY() << ' ' << arr[i].getZ() << '\n';
}

void ArrayOfPoints::insertionSort(){
    Point tempValue;
    for (int i = 1; i < size; i++){
        tempValue = arr[i];
        int j = i-1;
        while (tempValue.moreThan(arr[j]) == -1 && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tempValue;
    }
}
