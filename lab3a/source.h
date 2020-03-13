//
// Created by Admin on 13.03.2020.
//

#ifndef LAB3A_SOURCE_H
#define LAB3A_SOURCE_H

class Point{
private:
    double x, y, z;
public:
    Point();
    Point(double newX, double newY, double newZ);

    int comparePointWith(Point another);
};

#endif //LAB3A_SOURCE_H
