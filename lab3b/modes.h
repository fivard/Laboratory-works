//
// Created by Admin on 22.03.2020.
//

#ifndef LAB3B_MODES_H
#define LAB3B_MODES_H
#include <iostream>
#include "functions.h"

using namespace std;

void interactive();

void demonstration();

void benchmark();

double timeComboSort(MessageLog workingLog, vector<string> comparisonFields);
double timeCountingSort(MessageLog workingLog);
double timeRadixSort(MessageLog workingLog);
#endif //LAB3B_MODES_H
