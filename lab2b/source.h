//
// Created by Admin on 03.03.2020.
//

#ifndef LAB2B_SOURCE_H
#define LAB2B_SOURCE_H

#include <cstdio>
#include <cmath>
#include <iostream>

class HashedArrayTree{
private:
    int **top;
    size_t size;
    size_t power;

    void doubleArr() {
        int **newTop = new int* [2<<power];

        for (size_t i = 0; i < (2<<(power-2)); i++){
            newTop[i] = new int [2<<power];
        }

        for (size_t i = (2<<(power-2)); i < (2<<power); i++) {
            newTop[i] = nullptr;
        }

        for (size_t i = 0; i < (2<<(power-1)); i++)
            for (size_t j = 0; j < (2<<(power-1)); j++)
                newTop[i/2][j+i%2*(2<<(power-1))] = top[i][j];

        power++;
        top = newTop;
    }

    void halveArr(){
        power--;
        size_t newTopSize = 2<<(power-1);
        int **newTop = new int* [newTopSize];

        for (size_t i = 0; i < (newTopSize>>1); i++){
            newTop[i] = new int [newTopSize];
        }

        for (size_t i = (newTopSize>>1); i < newTopSize; i++){
            newTop[i] = nullptr;
        }

        for (size_t i = 0; i < (newTopSize>>1); i++)
            for (size_t j = 0; j < newTopSize; j++) {
                newTop[i][j] = top[i / 2][j + i % 2 * newTopSize];
            }

        top = newTop;
    }

public:
    HashedArrayTree();
    ~HashedArrayTree();
    int sizeOfTree();

    void push_back(int value);

    void pop_back();

    void insertByIndex(int value, int index);

    void deleteByIndex(int index);

    void outputTree();

    void clear();

    bool empty();

    int searchByIndex(int index);

    int searchByValue(int value);

    void generateSomeElementsToTheEnd(int n);

};

#endif //LAB2B_SOURCE_H
