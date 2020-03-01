//
// Created by Admin on 25.02.2020.
//

#ifndef LAB2_MODES_H
#define LAB2_MODES_H

#include "source.h"
#include <ctime>

void interactive();

bool chooseStructure(int action);

void workWithArray();
bool chooseArrayAction(int action, Stack<Circle>& stack);
void workWithVector();
bool chooseVectorAction(int action, Stack<Circle>& stack);
void workWithList();
bool chooseListAction(int action, Stack<Circle>& stack);

void demonstration();

void demoArr(Stack<Circle> stack);
void demoVec(Stack<Circle> stack);
void demoList(Stack<Circle> stack);

void benchmark();

void benchmarkArr();
void benchmarkVec();
void benchmarkList();


Circle inputCircle();
#endif //LAB2_MODES_H
