//
// Created by Admin on 15.03.2020.
//

#include "modes.h"

void demonstration(){
    cout << "Enter number of elements\n";
    int size;
    cin >> size;
    cout << "Enter threshold\n";
    int threshold;
    cin >> threshold;
    
    ArrayOfPoints newPoints(size);
    newPoints.generateArray();
    newPoints.output();
    newPoints.comboSort(0, size-1,threshold);
    cout << "SORT\n";
    newPoints.output();
}

void benchmark(){
    return;
}