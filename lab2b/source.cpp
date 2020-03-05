//
// Created by Admin on 05.03.2020.
//

#include "source.h"

HashedArrayTree::HashedArrayTree() {
    top = new int* [4];
    top[0] = new int [4];
    size = 0;
    power = 2;
}

HashedArrayTree::~HashedArrayTree(){
    std::cout << "destructor\n";
    for (size_t i = 0; top[i] != nullptr && i < (2<<(power-1)); i++)
        delete [] top[i];
    delete [] top;
}

void HashedArrayTree::coutTree() {
    for (size_t i = 0; i < (2<<(power-1)); i++) {
        std::cout << "array " << i << ": ";
        if (size <= i*(2<<(power-1)) )
            std::cout << "not exist";
        else {
            for (size_t j = 0; j < (2 << (power - 1)); j++)
                std::cout << top[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void HashedArrayTree::push_back(int value) {
    if (size == pow(4,power) ){
        std::cout << "double\n";
        doubleArr();
        push_back(value);
        return;
    }

    if (size%(2<<(power-1)) == 0 && size != 0){
        top[size>>power] = new int [2<<(power-1)];
        top[size>>power][0] = value;
        size++;

    }else{

        top[size>>power][size-(size>>power)*(2<<(power-1))] = value;
        size++;
    }
}

void HashedArrayTree::pop_back() {
    size--;

    if (size%(2<<(power-1)) == 0 && size != 0)
        delete[] top[size>>power];

    if (size*8 == pow(4, power) && power != 2) {
        std::cout << "halve\n";
        halveArr();
    }
}