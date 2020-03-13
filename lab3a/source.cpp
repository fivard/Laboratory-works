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

int Point::comparePointWith(Point another) {
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