//
// Created by Admin on 24.05.2020.
//

#ifndef LAB5_GRAPHS_SOURCE_H
#define LAB5_GRAPHS_SOURCE_H

#include <iostream>
#include <vector>

using namespace std;

class AdjacencyMatrix{
private:
    void addNewEdge(int startedPoint, int lastPoint, int weight);
    void doubleMatrixSize();

    int sizeOfMatrix;
    int countOfPoints;
    bool approximate;
    int **matrix;
public:
    AdjacencyMatrix(int newSize, bool newApproximate);
    ~AdjacencyMatrix();

    void output();
    void addNewEdge();
    void addNewNode();
};
#endif //LAB5_GRAPHS_SOURCE_H
