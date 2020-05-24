//
// Created by Admin on 24.05.2020.
//

#include "graphs_source.h"

AdjacencyMatrix::AdjacencyMatrix(int newCountOfPoints, bool newApproximate) {
    countOfPoints = newCountOfPoints;
    sizeOfMatrix = 2*countOfPoints;
    approximate = newApproximate;
    matrix = new int*[sizeOfMatrix];
    for (int i = 0; i < sizeOfMatrix; i++)
        matrix[i] = new int[sizeOfMatrix];

    for (int i = 0; i < sizeOfMatrix; i++)
        for (int j = 0; j < sizeOfMatrix; j++)
            matrix[i][j] = 0;
}
AdjacencyMatrix::~AdjacencyMatrix() {
    cout << "destructor\n";
    for(int i = 0; i < sizeOfMatrix; i++)
        delete matrix[i];
    delete matrix;
}

void AdjacencyMatrix::addNewEdge(int startedPoint, int lastPoint, int weight) {
    matrix[startedPoint][lastPoint] = weight;
    if (!approximate)
        matrix[lastPoint][startedPoint] = weight;
}
void AdjacencyMatrix::doubleMatrixSize(){
    sizeOfMatrix = sizeOfMatrix*2;
    int **newMatrix = new int*[sizeOfMatrix];
    for (int i = 0; i < sizeOfMatrix; i++)
        newMatrix[i] = new int[sizeOfMatrix];

    for (int i = 0; i < sizeOfMatrix; i++)
        for (int j = 0; j < sizeOfMatrix; j++)
            matrix[i][j] = 0;

    for (int i = 0; i < countOfPoints; i++)
        for (int j = 0; j < countOfPoints; j++)
            newMatrix[i][j] = matrix[i][j];
}

void AdjacencyMatrix::output() {
    for (int i = 0; i < countOfPoints; i++) {
        for (int j = 0; j < countOfPoints; j++)
            cout << matrix[i][j] << '\t';
        cout << "\n";
    }
}
void AdjacencyMatrix::addNewEdge() {
    cout << "Enter a weight(weight can't equal to 0)\n";
    int weight;
    cin >> weight;
    if (weight == 0){
        cout << "Incorrect weight\n";
        return;
    }

    cout << "\nChoose first point:\n";
    for (int i = 0; i < countOfPoints; i++)
        cout << i << ' ';
    cout << '\n';
    int startedPoint;
    cin >> startedPoint;

    cout << "\nChoose destination point:\n";
    for (int i = 0; i < countOfPoints; i++)
        if (i != startedPoint)
            cout << i << ' ';
    cout << '\n';
    int destinationPoint;
    cin >> destinationPoint;

    if (destinationPoint == startedPoint || startedPoint>=countOfPoints || startedPoint<0 || destinationPoint>=countOfPoints || destinationPoint<0){
        cout << "Incorrect points";
        return;
    }


    if (matrix[startedPoint][destinationPoint] == 0)
        matrix[startedPoint][destinationPoint] = weight;
    else {
        cout << "This edge is already exist\n";
        return;
    }

    if (!approximate)
        matrix[destinationPoint][startedPoint] = weight;
}
void AdjacencyMatrix::addNewNode() {
    countOfPoints++;
    if (countOfPoints > sizeOfMatrix)
        doubleMatrixSize();
}