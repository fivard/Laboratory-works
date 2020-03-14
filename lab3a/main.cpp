#include "source.h"

int main() {
    ArrayOfPoints newPoints(10);
    newPoints.generateArray();
    newPoints.output();
    newPoints.insertionSort();
    cout << "SORT\n";
    newPoints.output();
    return 0;
}
