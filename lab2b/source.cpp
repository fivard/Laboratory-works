//
// Created by Admin on 05.03.2020.
//

#include "source.h"

HashedArrayTree::HashedArrayTree() {
    top = new int* [4];
    for (size_t i = 0; i < 4; i++)
        top[i] = nullptr;
    top[0] = new int [4];
    size = 0;
    power = 2;
}

HashedArrayTree::~HashedArrayTree(){
    std::cout << "destructor\n";
    for (size_t i = 0; i < (2<<(power-1)); i++)
        delete [] top[i];
    delete [] top;
}

int HashedArrayTree::sizeOfTree() {
    return size;
}

void HashedArrayTree::outputTree() {
    for (size_t i = 0; i < (2<<(power-1)); i++) {
        std::cout << "array " << i << ": ";
        if (top[i] == nullptr )
            std::cout << "not exist";
        else {
            for (size_t j = 0; i*(2<<(power-1))+j < size && j < (2<<(power-1)); j++)
                std::cout << top[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void HashedArrayTree::push_back(int value) {
    if (size == pow(4,power) ){
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
    if (size == 0){
        std::cout << "Tree is already empty\n";
        return;
    }

    size--;
    top[(size>>power)][size%(2<<(power-1))] = 0;

    if (size % (2 << (power - 1)) == 0 && size != 0){
        delete[] top[size >> power];
        top[size>>power] = nullptr;
    }

    if (size*8 == pow(4, power) && power != 2) {
        halveArr();
    }
}

void HashedArrayTree::insertByIndex(int value, int index) {
    while (index > size+1 || index <= 0){
        std::cout << "Index is out of range. Enter index in range of 1 and " << size+1 << std::endl;
        std::cin >> index;
    }

    if (empty()) {
        push_back(value);
        return;
    }

    if (index == size + 1){
        push_back(value);
        return;
    }

    int lastElement = top[((size-1)>>power)][(size-1)%(2<<(power-1))];

    for (size_t i = size-1; i >= index; i--) {
        size_t lower_i = i - 1;
        top[(i >> power)][i % (2 << (power - 1))] = top[(lower_i >> power)][lower_i % (2 << (power - 1))];
    }

    push_back(lastElement);

    top[((index-1)>>power)][(index-1)%(2<<(power-1))] = value;

}

void HashedArrayTree::deleteByIndex(int index){
    if (empty()){
        std::cout << "Tree is already empty\n";
    }
    while (index > size || index <= 0){
        std::cout << "Index is out of range. Enter index in range of 1 and " << size << std::endl;
        std::cin >> index;
    }

    for (size_t i = index; i < size; i++) {
        size_t lower_i = i - 1;
        top[(lower_i >> power)][lower_i % (2 << (power - 1))] = top[(i >> power)][i % (2 << (power - 1))];
    }

    pop_back();
}

void HashedArrayTree::clear() {
    int **newTop = new int*[4];
    for (size_t i = 0; i < 4; i++)
        newTop[i] = nullptr;
    newTop[0] = new int[4];
    size = 0;
    power = 2;
    top = newTop;
}

bool HashedArrayTree::empty() {
    return size==0;
}

int HashedArrayTree::searchByIndex(int index) {
    while (index < 1 || index > size){
        std::cout << "Incorrect index. Try again\n";
        std::cin >> index;
    }
    return top[(index-1)>>power][(index-1)%(2<<(power-1))];
}

int HashedArrayTree::searchByValue(int value) {
    for (size_t i = 0; i < (2<<(power-1)) && top[i] != nullptr;i++){
        for (size_t j = 0; i*(2<<(power-1))+j < size && j < (2<<(power-1)); j++) {
            if (top[i][j] == value)
                return i*(2<<(power-1))+j + 1;
        }
    }
    std::cout << "Nothing was found. 0 was returned\n";
    return 0;
}


void HashedArrayTree::generateSomeElementsToTheEnd(int n) {
    srand(1);
    for (int i = 1; i <= n; i++)
        push_back(rand());
}