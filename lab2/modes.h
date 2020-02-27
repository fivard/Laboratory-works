//
// Created by Admin on 25.02.2020.
//

#ifndef LAB2_MODES_H
#define LAB2_MODES_H

#include "source.h"

void interactive();

void chooseStructure(int action);

void workWithArray();
void chooseArrayAction(int action, Stack<Circle>& stack);
void workWithVector();
void chooseVectorAction(int action, Stack<Circle>& stack);
void workWithList();
void chooseListAction(int action, Stack<Circle>& stack);

void demonstration();

void demoArr();
void demoVec();
void demoList();

void benchmark();


Circle inputCircle();
#endif //LAB2_MODES_H
